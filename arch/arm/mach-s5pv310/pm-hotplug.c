/* linux/arch/arm/mach-s5pv310/pm-hotplug.c
 *
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com/
 *
 * S5PV310 - Dynamic CPU hotpluging
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/serial_core.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/cpu.h>
#include <linux/percpu.h>
#include <linux/ktime.h>
#include <linux/tick.h>
#include <linux/kernel_stat.h>
#include <linux/sched.h>
#include <linux/suspend.h>
#include <linux/reboot.h>
#include <linux/earlysuspend.h>

#include <plat/map-base.h>
#include <plat/gpio-cfg.h>

#include <mach/regs-gpio.h>
#include <mach/regs-irq.h>
#include <linux/gpio.h>
#include <linux/cpufreq.h>

#define CPUMON 0

#define CHECK_DELAY	(.5*HZ)
#define TRANS_LOAD_L	20
#define TRANS_LOAD_H	50

#define HOTPLUG_UNLOCKED 0
#define HOTPLUG_LOCKED 1

#define HOTPLUG_ON_SCREEN 0 //1 = Hotplug on screen on/off only

static struct workqueue_struct *hotplug_wq;

static struct delayed_work hotplug_work;

static unsigned int hotpluging_rate = CHECK_DELAY;
module_param_named(rate, hotpluging_rate, uint, 0644);
static unsigned int user_lock;
module_param_named(lock, user_lock, uint, 0644);
static unsigned int trans_load_l = TRANS_LOAD_L;
module_param_named(loadl, trans_load_l, uint, 0644);
static unsigned int trans_load_h = TRANS_LOAD_H;
module_param_named(loadh, trans_load_h, uint, 0644);
static unsigned int last_freq = 0;

struct cpu_time_info {
	cputime64_t prev_cpu_idle;
	cputime64_t prev_cpu_wall;
	unsigned int load;
};

static DEFINE_PER_CPU(struct cpu_time_info, hotplug_cpu_time);

static bool screen_off;

/* mutex can be used since hotplug_timer does not run in
   timer(softirq) context but in process context */
static DEFINE_MUTEX(hotplug_lock);
#if !HOTPLUG_ON_SCREEN
static void hotplug_timer(struct work_struct *work)
{
	unsigned int i, avg_load = 0, load = 0;
	unsigned int cur_freq;

	mutex_lock(&hotplug_lock);

	if (screen_off) {
		if (!cpu_online(1)) {
                printk(KERN_INFO "pm-hotplug: disable cpu auto-hotplug\n");
                goto out; //if screen off and 1-core then don't hotplug
		}
	}

	if (user_lock == 1)
		goto no_hotplug;

/*	for_each_online_cpu(i) {
		struct cpu_time_info *tmp_info;
		cputime64_t cur_wall_time, cur_idle_time;
		unsigned int idle_time, wall_time;

		tmp_info = &per_cpu(hotplug_cpu_time, i);

		cur_idle_time = get_cpu_idle_time_us(i, &cur_wall_time);

		idle_time = (unsigned int)cputime64_sub(cur_idle_time,
							tmp_info->prev_cpu_idle);
		tmp_info->prev_cpu_idle = cur_idle_time;

		wall_time = (unsigned int)cputime64_sub(cur_wall_time,
							tmp_info->prev_cpu_wall);
		tmp_info->prev_cpu_wall = cur_wall_time;

		if (wall_time < idle_time)
			goto no_hotplug;

		tmp_info->load = 100 * (wall_time - idle_time) / wall_time;

		load += tmp_info->load;
	}

	avg_load = load / num_online_cpus();
*/
	cur_freq = cpufreq_get(0);

	//if ((avg_load < trans_load_l) || (cur_freq <= 200 * 1000)) {
	if ((cur_freq <= 200 * 1000) && (last_freq <= 200 * 1000)) {
		if (cpu_online(1) == 1) {
		printk("cpu1 turning off!\n");
		cpu_down(1);
#if CPUMON
		printk(KERN_ERR "CPUMON D %d\n", avg_load);
#endif
		printk("cpu1 off end!\n");
		}
		hotpluging_rate = CHECK_DELAY; //Low load
	//} else if ((avg_load > trans_load_h) && (cur_freq > 200 * 1000)) {
	} else if ((cur_freq > 500 * 1000) && (last_freq > 500 * 1000)) {
		//Start of if-1-cpu section
		if (cpu_online(1) == 0) {

	//Start of CPU load section
	for_each_online_cpu(i) {
		struct cpu_time_info *tmp_info;
		cputime64_t cur_wall_time, cur_idle_time;
		unsigned int idle_time, wall_time;

		tmp_info = &per_cpu(hotplug_cpu_time, i);

		cur_idle_time = get_cpu_idle_time_us(i, &cur_wall_time);

		idle_time = (unsigned int)cputime64_sub(cur_idle_time,
						tmp_info->prev_cpu_idle);
		tmp_info->prev_cpu_idle = cur_idle_time;

		wall_time = (unsigned int)cputime64_sub(cur_wall_time,
						tmp_info->prev_cpu_wall);
		tmp_info->prev_cpu_wall = cur_wall_time;

		if (wall_time < idle_time) {
			hotpluging_rate = CHECK_DELAY; //Short delay
			goto no_hotplug;
		}

		tmp_info->load = 100 * (wall_time - idle_time) / wall_time;

		load += tmp_info->load;
	}

	avg_load = load / num_online_cpus();
	//End of CPU load section

	if (avg_load > trans_load_h) {

		printk("cpu1 turning on!\n");
		cpu_up(1);
#if CPUMON
		printk(KERN_ERR "CPUMON U %d\n", avg_load);
#endif
		printk("cpu1 on end!\n");
		hotpluging_rate = CHECK_DELAY * 4; //High load, 2-core
		} else {
		hotpluging_rate = CHECK_DELAY; //Low load, 1-core
		}
		//End of if-1-cpu section
		}
	} else {
		if (cpu_online(1) == 1)
	                hotpluging_rate = CHECK_DELAY * 4; //Med load, 2-core
		else
			hotpluging_rate = CHECK_DELAY; //Med load, 1-core
	}

 no_hotplug:
	last_freq = cur_freq;
	queue_delayed_work_on(0, hotplug_wq, &hotplug_work, hotpluging_rate);
 out:
	mutex_unlock(&hotplug_lock);
}
#endif
static int s5pv310_pm_hotplug_notifier_event(struct notifier_block *this,
					     unsigned long event, void *ptr)
{
	static unsigned user_lock_saved;

	switch (event) {
	case PM_SUSPEND_PREPARE:
		mutex_lock(&hotplug_lock);
		user_lock_saved = user_lock;
		user_lock = 1;
		pr_info("%s: saving pm_hotplug lock %x\n",
			__func__, user_lock_saved);
		mutex_unlock(&hotplug_lock);
		return NOTIFY_OK;
	case PM_POST_RESTORE:
	case PM_POST_SUSPEND:
		mutex_lock(&hotplug_lock);
		pr_info("%s: restoring pm_hotplug lock %x\n",
			__func__, user_lock_saved);
		user_lock = user_lock_saved;
		mutex_unlock(&hotplug_lock);
		return NOTIFY_OK;
	}
	return NOTIFY_DONE;
}

static struct notifier_block s5pv310_pm_hotplug_notifier = {
	.notifier_call = s5pv310_pm_hotplug_notifier_event,
};

static int hotplug_reboot_notifier_call(struct notifier_block *this,
					unsigned long code, void *_cmd)
{
	mutex_lock(&hotplug_lock);
	pr_err("%s: disabling pm hotplug\n", __func__);
	user_lock = 1;
	mutex_unlock(&hotplug_lock);

	return NOTIFY_DONE;
}

static struct notifier_block hotplug_reboot_notifier = {
	.notifier_call = hotplug_reboot_notifier_call,
};

static void hotplug_early_suspend(struct early_suspend *handler)
{
	mutex_lock(&hotplug_lock);
	screen_off = true;
#if HOTPLUG_ON_SCREEN
	if (cpu_online(1)) cpu_down(1);
#endif
	mutex_unlock(&hotplug_lock);
}

static void hotplug_late_resume(struct early_suspend *handler)
{
	printk(KERN_INFO "pm-hotplug: enable cpu auto-hotplug\n");

	mutex_lock(&hotplug_lock);
	screen_off = false;
#if HOTPLUG_ON_SCREEN
	if (!cpu_online(1)) cpu_up(1);
#else
	queue_delayed_work_on(0, hotplug_wq, &hotplug_work, hotpluging_rate);
#endif
	mutex_unlock(&hotplug_lock);
}

static struct early_suspend hotplug_early_suspend_notifier = {
	.suspend = hotplug_early_suspend,
	.resume = hotplug_late_resume,
	.level = EARLY_SUSPEND_LEVEL_BLANK_SCREEN,
};

static int __init s5pv310_pm_hotplug_init(void)
{
	printk(KERN_INFO "SMDKV310 PM-hotplug init function\n");
#if !HOTPLUG_ON_SCREEN
	hotplug_wq = create_singlethread_workqueue("dynamic hotplug");
	if (!hotplug_wq) {
		printk(KERN_ERR "Creation of hotplug work failed\n");
		return -EFAULT;
	}

	INIT_DELAYED_WORK_DEFERRABLE(&hotplug_work, hotplug_timer);

	queue_delayed_work_on(0, hotplug_wq, &hotplug_work, 60 * HZ);
#endif
	register_pm_notifier(&s5pv310_pm_hotplug_notifier);
	register_reboot_notifier(&hotplug_reboot_notifier);
	register_early_suspend(&hotplug_early_suspend_notifier);

	return 0;
}

late_initcall(s5pv310_pm_hotplug_init);

static struct platform_device s5pv310_pm_hotplug_device = {
	.name = "s5pv310-dynamic-cpu-hotplug",
	.id = -1,
};

static int __init s5pv310_pm_hotplug_device_init(void)
{
	int ret;

	ret = platform_device_register(&s5pv310_pm_hotplug_device);

	if (ret) {
		printk(KERN_ERR "failed at(%d)\n", __LINE__);
		return ret;
	}

	printk(KERN_INFO "s5pv310_pm_hotplug_device_init: %d\n", ret);

	return ret;
}

late_initcall(s5pv310_pm_hotplug_device_init);
