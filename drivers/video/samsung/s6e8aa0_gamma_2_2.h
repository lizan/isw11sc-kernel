#ifndef __S6E8AA0_GAMMA_2_2_H__
#define __S6E8AA0_GAMMA_2_2_H__

#if CONFIG_MACH_C1_KDDI_REV00
#include "s6e8aa0_param_kddi_dali.h"
#else
#include "s6e8aa0_param.h"
#endif


const unsigned char acl_cutoff_40[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x06, 0x0C, 0x11, 0x16, 0x1C, 0x21,
	0x26, 0x2B, 0x31, 0x36
};

const unsigned char acl_cutoff_43[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x07, 0x0C, 0x12, 0x18, 0x1E, 0x23,
	0x29, 0x2F, 0x34, 0x3A
};

const unsigned char acl_cutoff_45[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x07, 0x0D, 0x13, 0x19, 0x1F, 0x25,
	0x2B, 0x31, 0x37, 0x3D
};

const unsigned char acl_cutoff_47[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x07, 0x0E, 0x14, 0x1B, 0x21, 0x27,
	0x2E, 0x34, 0x3B, 0x41
};

const unsigned char acl_cutoff_48[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x08, 0x0E, 0x15, 0x1B, 0x22, 0x29,
	0x2F, 0x36, 0x3C, 0x43
};

const unsigned char acl_cutoff_50[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53, 0x00, 0x00,
	0x03, 0x1F, 0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x08, 0x0F, 0x16, 0x1D, 0x24, 0x2A,
	0x31, 0x38, 0x3F, 0x46
};

const unsigned char * acl_cutoff_table[ACL_STATUS_MAX] = {
	SEQ_ACL_OFF,
	acl_cutoff_40,
	acl_cutoff_43,
	acl_cutoff_45,
	acl_cutoff_47,
	acl_cutoff_48,
	acl_cutoff_50,
};

#define ACL_PARAM_SIZE	ARRAY_SIZE(acl_cutoff_50)


const unsigned char elvss_32[] = {
	0xD9,
	0x14, 0x40, 0x0C, 0xCB, 0xCE,
	0x6E, 0xC4, 0x07, 0x40, 0x40,
	0xD0, 0x00, 0x60, 0x19
};

const unsigned char elvss_34[] = {
	0xD9,
	0x14, 0x40, 0x0C, 0xCB, 0xCE,
	0x6E, 0xC4, 0x0F, 0x40, 0x40,
	0xDD, 0x00, 0x60, 0x19
};

const unsigned char elvss_38[] = {
	0xD9,
	0x14, 0x40, 0x0C, 0xCB, 0xCE,
	0x6E, 0xC4, 0x0F, 0x40, 0x40,
	0xD9, 0x00, 0x60, 0x19
};

const unsigned char elvss_47[] = {
	0xD9,
	0x14, 0x40, 0x0C, 0xCB, 0xCE,
	0x6E, 0xC4, 0x0F, 0x40, 0x40,
	0xD0, 0x00, 0x60, 0x19
};


const unsigned char *elvss_table[ELVSS_STATUS_MAX] = {
	elvss_32,
	elvss_34,
	elvss_38,
	elvss_47,
};

#define ELVSS_PARAM_SIZE	ARRAY_SIZE(elvss_47)


#define GAMMA_PARAM_SIZE	26


const unsigned char gamma22_30[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xDF, 0x1F, 0xD7, 0xDC, 0xB7, 0xE1,
	0xC0, 0xAF, 0xC4, 0xD2, 0xD0, 0xCF,
	0x00, 0x4D, 0x00, 0x40, 0x00, 0x5F,
};

const unsigned char gamma22_40[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD5, 0x35, 0xCF, 0xDC, 0xC1, 0xE1,
	0xBF, 0xB3, 0xC1, 0xD2, 0xD1, 0xCE,
	0x00, 0x53, 0x00, 0x46, 0x00, 0x67,
};

const unsigned char gamma22_50[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD2, 0x64, 0xCF, 0xDB, 0xC6, 0xE1,
	0xBD, 0xB3, 0xBD, 0xD2, 0xD2, 0xCE,
	0x00, 0x59, 0x00, 0x4B, 0x00, 0x6E,
};

const unsigned char gamma22_60[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD0, 0x7C, 0xCF, 0xDB, 0xC9, 0xE0,
	0xBC, 0xB4, 0xBB, 0xCF, 0xD1, 0xCC,
	0x00, 0x5F, 0x00, 0x50, 0x00, 0x75,
};

const unsigned char gamma22_70[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD0, 0x8E, 0xD1, 0xDB, 0xCC, 0xDF,
	0xBB, 0xB6, 0xB9, 0xD0, 0xD1, 0xCD,
	0x00, 0x63, 0x00, 0x54, 0x00, 0x7A,
};

const unsigned char gamma22_80[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD1, 0x9E, 0xD5, 0xDA, 0xCD, 0xDD,
	0xBB, 0xB7, 0xB9, 0xCE, 0xCE, 0xC9,
	0x00, 0x68, 0x00, 0x59, 0x00, 0x81,
};

const unsigned char gamma22_90[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xD0, 0xA5, 0xD6, 0xDA, 0xCF, 0xDD,
	0xBB, 0xB7, 0xB8, 0xCC, 0xCD, 0xC7,
	0x00, 0x6C, 0x00, 0x5C, 0x00, 0x86,
};

const unsigned char gamma22_100[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x00, 0xFF,
	0xCF, 0xA7, 0xD6, 0xDA, 0xD0, 0xDC,
	0xB8, 0xB6, 0xB5, 0xCB, 0xCC, 0xC6,
	0x00, 0x71, 0x00, 0x60, 0x00, 0x8C,
};

const unsigned char gamma22_110[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x1F, 0xFE,
	0xD0, 0xAE, 0xD7, 0xD9, 0xD0, 0xDB,
	0xB9, 0xB6, 0xB5, 0xCA, 0xCC, 0xC5,
	0x00, 0x74, 0x00, 0x63, 0x00, 0x90,
};

const unsigned char gamma22_120[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x1F, 0xF9,
	0xCF, 0xB0, 0xD6, 0xD9, 0xD1, 0xDB,
	0xB9, 0xB6, 0xB4, 0xCA, 0xCB, 0xC5,
	0x00, 0x77, 0x00, 0x66, 0x00, 0x94,
};

const unsigned char gamma22_130[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFF, 0x1F, 0xF7,
	0xCF, 0xB3, 0xD7, 0xD8, 0xD1, 0xD9,
	0xB7, 0xB6, 0xB3, 0xC9, 0xCA, 0xC3,
	0x00, 0x7B, 0x00, 0x69, 0x00, 0x99,
};

const unsigned char gamma22_140[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFD, 0x2F, 0xF7,
	0xDF, 0xB5, 0xD6, 0xD8, 0xD1, 0xD8,
	0xB6, 0xB5, 0xB2, 0xCA, 0xCB, 0xC4,
	0x00, 0x7E, 0x00, 0x6C, 0x00, 0x9D,

};

const unsigned char gamma22_150[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFB, 0x2F, 0xF5,
	0xD0, 0xB7, 0xD7, 0xD7, 0xD1, 0xD8,
	0xB6, 0xB5, 0xB1, 0xC8, 0xCA, 0xC3,
	0x00, 0x81, 0x00, 0x6E, 0x00, 0xA0,
};

const unsigned char gamma22_160[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xFA, 0x2F, 0xF5,
	0xCE, 0xB6, 0xD5, 0xD7, 0xD2, 0xD8,
	0xB6, 0xB4, 0xB0, 0xC7, 0xC9, 0xC1,
	0x00, 0x84, 0x00, 0x71, 0x00, 0xA5,
};

const unsigned char gamma22_170[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xF7, 0x2F, 0xF2,
	0xCE, 0xB9, 0xD5, 0xD8, 0xD2, 0xD8,
	0xB4, 0xB4, 0xAF, 0xC7, 0xC9, 0xC1,
	0x00, 0x87, 0x00, 0x73, 0x00, 0xA8,
};

const unsigned char gamma22_180[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xF5, 0x2F, 0xF0,
	0xDF, 0xBA, 0xD5, 0xD7, 0xD2, 0xD7,
	0xB4, 0xB4, 0xAF, 0xC5, 0xC7, 0xBF,
	0x00, 0x8A, 0x00, 0x76, 0x00, 0xAC,
};

const unsigned char gamma22_190[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xF2, 0x2F, 0xED,
	0xCE, 0xBB, 0xD4, 0xD6, 0xD2, 0xD6,
	0xB5, 0xB4, 0xAF, 0xC5, 0xC7, 0xBF,
	0x00, 0x8c, 0x00, 0x78, 0x00, 0xAF,
};

const unsigned char gamma22_200[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xF2, 0x2F, 0xED,
	0xCE, 0xBB, 0xD4, 0xD7, 0xD3, 0xD6,
	0xB3, 0xB3, 0xAE, 0xC6, 0xC7, 0xBF,
	0x00, 0x8E, 0x00, 0x7A, 0x00, 0xB2,
};

const unsigned char gamma22_210[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEF, 0x2F, 0xEB,
	0xCD, 0xBB, 0xD2, 0xD7, 0xD3, 0xD6,
	0xB3, 0xB4, 0xAE, 0xC5, 0xC6, 0xBE,
	0x00, 0x91, 0x00, 0x7D, 0x00, 0xB6,
};

const unsigned char gamma22_220[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEE, 0x2F, 0xEA,
	0xCE, 0xBD, 0xD4, 0xD6, 0xD2, 0xD5,
	0xB2, 0xB3, 0xAD, 0xC3, 0xC4, 0xBB,
	0x00, 0x94, 0x00, 0x7F, 0x00, 0xBA,
};

const unsigned char gamma22_230[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEC, 0x2F, 0xE8,
	0xCE, 0xBE, 0xD3, 0xD6, 0xD3, 0xD5,
	0xB2, 0xB2, 0xAC, 0xC3, 0xC5, 0xBC,
	0x00, 0x96, 0x00, 0x81, 0x00, 0xBD,
};

const unsigned char gamma22_240[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEB, 0x2F, 0xE7,
	0xCE, 0xBF, 0xD3, 0xD6, 0xD2, 0xD5,
	0xB1, 0xB2, 0xAB, 0xC2, 0xC4, 0xBB,
	0x00, 0x99, 0x00, 0x83, 0x00, 0xC0,
};

const unsigned char gamma22_250[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEF, 0x5F, 0xE9,
	0xCA, 0xBF, 0xD3, 0xD5, 0xD2, 0xD4,
	0xB2, 0xB2, 0xAB, 0xC1, 0xC4, 0xBA,
	0x00, 0x9B, 0x00, 0x85, 0x00, 0xC3,
};

const unsigned char gamma22_260[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xEA, 0x5F, 0xE8,
	0xCE, 0xBF, 0xD2, 0xD5, 0xD2, 0xD4,
	0xB1, 0xB2, 0xAB, 0xC1, 0xC2, 0xB9,
	0x00, 0x9D, 0x00, 0x87, 0x00, 0xC6,
};

const unsigned char gamma22_270[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xE9, 0x5F, 0xE7,
	0xCD, 0xBF, 0xD2, 0xD6, 0xD2, 0xD4,
	0xB1, 0xB2, 0xAB, 0xBE, 0xC0, 0xB7,
	0x00, 0xA1, 0x00, 0x8A, 0x00, 0xCA,
};

const unsigned char gamma22_280[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xE8, 0x61, 0xE6,
	0xCD, 0xBF, 0xD1, 0xD6, 0xD3, 0xD4,
	0xAF, 0xB0, 0xA9, 0xBE, 0xC1, 0xB7,
	0x00, 0xA3, 0x00, 0x8B, 0x00, 0xCE,
};

const unsigned char gamma22_290[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xE8, 0x62, 0xE5,
	0xCC, 0xC0, 0xD0, 0xD6, 0xD2, 0xD4,
	0xAF, 0xB1, 0xA9, 0xBD, 0xC0, 0xB6,
	0x00, 0xA5, 0x00, 0x8D, 0x00, 0xD0,
};

const unsigned char gamma22_300[GAMMA_PARAM_SIZE] = {
	0xFA, 0x01,
	0x1F, 0x1F, 0x1F, 0xE7, 0x7F, 0xE3,
	0xCC, 0xC1, 0xD0, 0xD5, 0xD3, 0xD3,
	0xAE, 0xAF, 0xA8, 0xBE, 0xC0, 0xB7,
	0x00, 0xA8, 0x00, 0x90, 0x00, 0xD3,
};


const unsigned char *gamma22_table[GAMMA_2_2_MAX] = {
	gamma22_30,
	gamma22_40,
	gamma22_70,
	gamma22_90,
	gamma22_100,
	gamma22_110,
	gamma22_120,
	gamma22_130,
	gamma22_140,
	gamma22_150,
	gamma22_160,
	gamma22_170,
	gamma22_180,
	gamma22_190,
	gamma22_200,
	gamma22_210,
	gamma22_220,
	gamma22_230,
	gamma22_240,
	gamma22_250,
	gamma22_260,
	gamma22_270,
	gamma22_280,
	gamma22_290,
	gamma22_300,
};


#endif /* __S6E8AA0_GAMMA_2_2_H__ */
