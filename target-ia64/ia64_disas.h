/*-
 * Copyright (c) 2000-2006 Marcel Moolenaar
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _IA64_DISAS_H_
#define	_IA64_DISAS_H_

#ifndef _IA64_DISAS_INT_H_
#define	IA64_ADDITIONAL_OPCODES		IA64_OP_NUMBER_OF_OPCODES
#endif

/* Application registers. */
#define	AR_K0		0
#define	AR_K1		1
#define	AR_K2		2
#define	AR_K3		3
#define	AR_K4		4
#define	AR_K5		5
#define	AR_K6		6
#define	AR_K7		7
#define	AR_RSC		16
#define	AR_BSP		17
#define	AR_BSPSTORE	18
#define	AR_RNAT		19
#define	AR_FCR		21
#define	AR_EFLAG	24
#define	AR_CSD		25
#define	AR_SSD		26
#define	AR_CFLG		27
#define	AR_FSR		28
#define	AR_FIR		29
#define	AR_FDR		30
#define	AR_CCV		32
#define	AR_UNAT		36
#define	AR_FPSR		40
#define	AR_ITC		44
#define	AR_PFS		64
#define	AR_LC		65
#define	AR_EC		66

/* Control registers. */
#define	CR_DCR		0
#define	CR_ITM		1
#define	CR_IVA		2
#define	CR_PTA		8
#define	CR_IPSR		16
#define	CR_ISR		17
#define	CR_IIP		19
#define	CR_IFA		20
#define	CR_ITIR		21
#define	CR_IIPA		22
#define	CR_IFS		23
#define	CR_IIM		24
#define	CR_IHA		25
#define	CR_LID		64
#define	CR_IVR		65
#define	CR_TPR		66
#define	CR_EOI		67
#define	CR_IRR0		68
#define	CR_IRR1		69
#define	CR_IRR2		70
#define	CR_IRR3		71
#define	CR_ITV		72
#define	CR_PMV		73
#define	CR_CMCV		74
#define	CR_LRR0		80
#define	CR_LRR1		81

enum ia64_cmpltr_class {
	IA64_CC_NONE,
	IA64_CC_ACLR,
	IA64_CC_BSW, IA64_CC_BTYPE, IA64_CC_BWH,
	IA64_CC_CHK, IA64_CC_CLRRRB, IA64_CC_CREL, IA64_CC_CTYPE,
	IA64_CC_DEP, IA64_CC_DH,
	IA64_CC_FC, IA64_CC_FCREL, IA64_CC_FCTYPE, IA64_CC_FCVT,
	IA64_CC_FLDTYPE, IA64_CC_FMERGE, IA64_CC_FREL, IA64_CC_FSWAP,
	IA64_CC_GETF,
	IA64_CC_IH, IA64_CC_INVALA, IA64_CC_IPWH, IA64_CC_ITC, IA64_CC_ITR,
	IA64_CC_LDHINT, IA64_CC_LDTYPE, IA64_CC_LFETCH, IA64_CC_LFHINT,
	IA64_CC_LFTYPE, IA64_CC_LR,
	IA64_CC_MF, IA64_CC_MOV, IA64_CC_MWH,
	IA64_CC_PAVG, IA64_CC_PC, IA64_CC_PH, IA64_CC_PREL, IA64_CC_PRTYPE,
	IA64_CC_PTC, IA64_CC_PTR, IA64_CC_PVEC,
	IA64_CC_SAT, IA64_CC_SEM, IA64_CC_SETF, IA64_CC_SF, IA64_CC_SRLZ,
	IA64_CC_STHINT, IA64_CC_STTYPE, IA64_CC_SYNC,
	IA64_CC_RW,
	IA64_CC_TREL, IA64_CC_TRUNC,
	IA64_CC_UNIT, IA64_CC_UNPACK, IA64_CC_UNS,
	IA64_CC_VMSW,
	IA64_CC_XMA
};

enum ia64_cmpltr_type {
	IA64_CT_NONE,
	IA64_CT_COND = IA64_CT_NONE,

	IA64_CT_0, IA64_CT_1,
	IA64_CT_A, IA64_CT_ACQ, IA64_CT_AND,
	IA64_CT_B, IA64_CT_BIAS,
	IA64_CT_C_CLR, IA64_CT_C_CLR_ACQ, IA64_CT_C_NC, IA64_CT_CALL,
	IA64_CT_CEXIT, IA64_CT_CLOOP, IA64_CT_CLR, IA64_CT_CTOP,
	IA64_CT_D, IA64_CT_DC_DC, IA64_CT_DC_NT, IA64_CT_DPNT, IA64_CT_DPTK,
	IA64_CT_E, IA64_CT_EQ, IA64_CT_EXCL, IA64_CT_EXIT, IA64_CT_EXP,
	IA64_CT_F, IA64_CT_FAULT, IA64_CT_FEW, IA64_CT_FILL, IA64_CT_FX,
	IA64_CT_FXU,
	IA64_CT_G, IA64_CT_GA, IA64_CT_GE, IA64_CT_GT,
	IA64_CT_H, IA64_CT_HU,
	IA64_CT_I, IA64_CT_IA, IA64_CT_IMP,
	IA64_CT_L, IA64_CT_LE, IA64_CT_LOOP, IA64_CT_LR, IA64_CT_LT,
	IA64_CT_LTU,
	IA64_CT_M, IA64_CT_MANY,
	IA64_CT_NC, IA64_CT_NE, IA64_CT_NEQ, IA64_CT_NL, IA64_CT_NLE,
	IA64_CT_NLT, IA64_CT_NM, IA64_CT_NR, IA64_CT_NS, IA64_CT_NT_DC,
	IA64_CT_NT_NT, IA64_CT_NT_TK, IA64_CT_NT1, IA64_CT_NT2, IA64_CT_NTA,
	IA64_CT_NZ,
	IA64_CT_OR, IA64_CT_OR_ANDCM, IA64_CT_ORD,
	IA64_CT_PR,
	IA64_CT_R, IA64_CT_RAZ, IA64_CT_REL, IA64_CT_RET, IA64_CT_RW,
	IA64_CT_S, IA64_CT_S0, IA64_CT_S1, IA64_CT_S2, IA64_CT_S3, IA64_CT_SA,
	IA64_CT_SE, IA64_CT_SIG, IA64_CT_SPILL, IA64_CT_SPNT, IA64_CT_SPTK,
	IA64_CT_SSS,
	IA64_CT_TK_DC, IA64_CT_TK_NT, IA64_CT_TK_TK, IA64_CT_TRUNC,
	IA64_CT_U, IA64_CT_UNC, IA64_CT_UNORD, IA64_CT_USS, IA64_CT_UUS,
	IA64_CT_UUU,
	IA64_CT_W, IA64_CT_WEXIT, IA64_CT_WTOP,
	IA64_CT_X, IA64_CT_XF,
	IA64_CT_Z,
};

/* Completer. */
struct ia64_cmpltr {
	enum ia64_cmpltr_class	c_class;
	enum ia64_cmpltr_type	c_type;
};

/* Operand types. */
enum ia64_oper_type {
	IA64_OPER_NONE,
	IA64_OPER_AREG,		/* = ar# */
	IA64_OPER_BREG,		/* = b# */
	IA64_OPER_CPUID,	/* = cpuid[r#] */
	IA64_OPER_CREG,		/* = cr# */
	IA64_OPER_DBR,		/* = dbr[r#] */
	IA64_OPER_DISP,		/* IP relative displacement. */
	IA64_OPER_DTR,		/* = dtr[r#] */
	IA64_OPER_FREG,		/* = f# */
	IA64_OPER_GREG,		/* = r# */
	IA64_OPER_IBR,		/* = ibr[r#] */
	IA64_OPER_IMM,		/* Immediate */
	IA64_OPER_IP,		/* = ip */
	IA64_OPER_ITR,		/* = itr[r#] */
	IA64_OPER_MEM,		/* = [r#] */
	IA64_OPER_MSR,		/* = msr[r#] */
	IA64_OPER_PKR,		/* = pkr[r#] */
	IA64_OPER_PMC,		/* = pmc[r#] */
	IA64_OPER_PMD,		/* = pmd[r#] */
	IA64_OPER_PR,		/* = pr */
	IA64_OPER_PR_ROT,	/* = pr.rot */
	IA64_OPER_PREG,		/* = p# */
	IA64_OPER_PSR,		/* = psr */
	IA64_OPER_PSR_L,	/* = psr.l */
	IA64_OPER_PSR_UM,	/* = psr.um */
	IA64_OPER_RR,		/* = rr[r#] */
	IA64_OPER_UNSPEC
};

/* Operand */
struct ia64_oper {
	enum ia64_oper_type	o_type;
	uint64_t		o_value;
};

/* Instruction formats. */
enum ia64_fmt {
	IA64_FMT_NONE,
	IA64_FMT_A = 0x0100,
	IA64_FMT_A1,  IA64_FMT_A2,  IA64_FMT_A3,  IA64_FMT_A4,
	IA64_FMT_A5,  IA64_FMT_A6,  IA64_FMT_A7,  IA64_FMT_A8,
	IA64_FMT_A9,  IA64_FMT_A10,
	IA64_FMT_B = 0x0200,
	IA64_FMT_B1,  IA64_FMT_B2,  IA64_FMT_B3,  IA64_FMT_B4,
	IA64_FMT_B5,  IA64_FMT_B6,  IA64_FMT_B7,  IA64_FMT_B8,
	IA64_FMT_B9,
	IA64_FMT_F = 0x0300,
	IA64_FMT_F1,  IA64_FMT_F2,  IA64_FMT_F3,  IA64_FMT_F4,
	IA64_FMT_F5,  IA64_FMT_F6,  IA64_FMT_F7,  IA64_FMT_F8,
	IA64_FMT_F9,  IA64_FMT_F10, IA64_FMT_F11, IA64_FMT_F12,
	IA64_FMT_F13, IA64_FMT_F14, IA64_FMT_F15, IA64_FMT_F16,
	IA64_FMT_I = 0x0400,
	IA64_FMT_I1,  IA64_FMT_I2,  IA64_FMT_I3,  IA64_FMT_I4,
	IA64_FMT_I5,  IA64_FMT_I6,  IA64_FMT_I7,  IA64_FMT_I8,
	IA64_FMT_I9,  IA64_FMT_I10, IA64_FMT_I11, IA64_FMT_I12,
	IA64_FMT_I13, IA64_FMT_I14, IA64_FMT_I15, IA64_FMT_I16,
	IA64_FMT_I17, IA64_FMT_I18, IA64_FMT_I19, IA64_FMT_I20,
	IA64_FMT_I21, IA64_FMT_I22, IA64_FMT_I23, IA64_FMT_I24,
	IA64_FMT_I25, IA64_FMT_I26, IA64_FMT_I27, IA64_FMT_I28,
	IA64_FMT_I29, IA64_FMT_I30,
	IA64_FMT_M = 0x0500,
	IA64_FMT_M1,  IA64_FMT_M2,  IA64_FMT_M3,  IA64_FMT_M4,
	IA64_FMT_M5,  IA64_FMT_M6,  IA64_FMT_M7,  IA64_FMT_M8,
	IA64_FMT_M9,  IA64_FMT_M10, IA64_FMT_M11, IA64_FMT_M12,
	IA64_FMT_M13, IA64_FMT_M14, IA64_FMT_M15, IA64_FMT_M16,
	IA64_FMT_M17, IA64_FMT_M18, IA64_FMT_M19, IA64_FMT_M20,
	IA64_FMT_M21, IA64_FMT_M22, IA64_FMT_M23, IA64_FMT_M24,
	IA64_FMT_M25, IA64_FMT_M26, IA64_FMT_M27, IA64_FMT_M28,
	IA64_FMT_M29, IA64_FMT_M30, IA64_FMT_M31, IA64_FMT_M32,
	IA64_FMT_M33, IA64_FMT_M34, IA64_FMT_M35, IA64_FMT_M36,
	IA64_FMT_M37, IA64_FMT_M38, IA64_FMT_M39, IA64_FMT_M40,
	IA64_FMT_M41, IA64_FMT_M42, IA64_FMT_M43, IA64_FMT_M44,
	IA64_FMT_M45, IA64_FMT_M46, IA64_FMT_M47, IA64_FMT_M48,
	IA64_FMT_X = 0x0600,
	IA64_FMT_X1,  IA64_FMT_X2,  IA64_FMT_X3,  IA64_FMT_X4,
	IA64_FMT_X5
};

/* Instruction opcodes. */
enum ia64_op {
	IA64_OP_NONE,
	IA64_OP_ADD, IA64_OP_ADDL, IA64_OP_ADDP4, IA64_OP_ADDS, IA64_OP_ALLOC,
	IA64_OP_AND, IA64_OP_ANDCM,
	IA64_OP_BR, IA64_OP_BREAK, IA64_OP_BRL, IA64_OP_BRP, IA64_OP_BSW,
	IA64_OP_CHK, IA64_OP_CLRRRB, IA64_OP_CMP, IA64_OP_CMP4,
	IA64_OP_CMP8XCHG16, IA64_OP_CMPXCHG1, IA64_OP_CMPXCHG2,
	IA64_OP_CMPXCHG4, IA64_OP_CMPXCHG8, IA64_OP_COVER, IA64_OP_CZX1,
	IA64_OP_CZX2,
	IA64_OP_DEP,
	IA64_OP_EPC, IA64_OP_EXTR,
	IA64_OP_FAMAX, IA64_OP_FAMIN, IA64_OP_FAND, IA64_OP_FANDCM, IA64_OP_FC,
	IA64_OP_FCHKF, IA64_OP_FCLASS, IA64_OP_FCLRF, IA64_OP_FCMP,
	IA64_OP_FCVT, IA64_OP_FETCHADD4, IA64_OP_FETCHADD8, IA64_OP_FLUSHRS,
	IA64_OP_FMA, IA64_OP_FMAX, IA64_OP_FMERGE, IA64_OP_FMIN, IA64_OP_FMIX,
	IA64_OP_FMS, IA64_OP_FNMA, IA64_OP_FOR, IA64_OP_FPACK, IA64_OP_FPAMAX,
	IA64_OP_FPAMIN, IA64_OP_FPCMP, IA64_OP_FPCVT, IA64_OP_FPMA,
	IA64_OP_FPMAX, IA64_OP_FPMERGE, IA64_OP_FPMIN, IA64_OP_FPMS,
	IA64_OP_FPNMA, IA64_OP_FPRCPA, IA64_OP_FPRSQRTA, IA64_OP_FRCPA,
	IA64_OP_FRSQRTA, IA64_OP_FSELECT, IA64_OP_FSETC, IA64_OP_FSWAP,
	IA64_OP_FSXT, IA64_OP_FWB, IA64_OP_FXOR,
	IA64_OP_GETF,
	IA64_OP_HINT,
	IA64_OP_INVALA, IA64_OP_ITC, IA64_OP_ITR,
	IA64_OP_LD1, IA64_OP_LD16, IA64_OP_LD2, IA64_OP_LD4, IA64_OP_LD8,
	IA64_OP_LDF, IA64_OP_LDF8, IA64_OP_LDFD, IA64_OP_LDFE, IA64_OP_LDFP8,
	IA64_OP_LDFPD, IA64_OP_LDFPS, IA64_OP_LDFS, IA64_OP_LFETCH,
	IA64_OP_LOADRS,
	IA64_OP_MF, IA64_OP_MIX1, IA64_OP_MIX2, IA64_OP_MIX4, IA64_OP_MOV,
	IA64_OP_MOVL, IA64_OP_MUX1, IA64_OP_MUX2,
	IA64_OP_NOP,
	IA64_OP_OR,
	IA64_OP_PACK2, IA64_OP_PACK4, IA64_OP_PADD1, IA64_OP_PADD2,
	IA64_OP_PADD4, IA64_OP_PAVG1, IA64_OP_PAVG2, IA64_OP_PAVGSUB1,
	IA64_OP_PAVGSUB2, IA64_OP_PCMP1, IA64_OP_PCMP2, IA64_OP_PCMP4,
	IA64_OP_PMAX1, IA64_OP_PMAX2, IA64_OP_PMIN1, IA64_OP_PMIN2,
	IA64_OP_PMPY2, IA64_OP_PMPYSHR2, IA64_OP_POPCNT, IA64_OP_PROBE,
	IA64_OP_PSAD1, IA64_OP_PSHL2, IA64_OP_PSHL4, IA64_OP_PSHLADD2,
	IA64_OP_PSHR2, IA64_OP_PSHR4, IA64_OP_PSHRADD2, IA64_OP_PSUB1,
	IA64_OP_PSUB2, IA64_OP_PSUB4, IA64_OP_PTC, IA64_OP_PTR,
	IA64_OP_RFI, IA64_OP_RSM, IA64_OP_RUM,
	IA64_OP_SETF, IA64_OP_SHL, IA64_OP_SHLADD, IA64_OP_SHLADDP4,
	IA64_OP_SHR, IA64_OP_SHRP, IA64_OP_SRLZ, IA64_OP_SSM, IA64_OP_ST1,
	IA64_OP_ST16, IA64_OP_ST2, IA64_OP_ST4, IA64_OP_ST8, IA64_OP_STF,
	IA64_OP_STF8, IA64_OP_STFD, IA64_OP_STFE, IA64_OP_STFS, IA64_OP_SUB,
	IA64_OP_SUM, IA64_OP_SXT1, IA64_OP_SXT2, IA64_OP_SXT4, IA64_OP_SYNC,
	IA64_OP_TAK, IA64_OP_TBIT, IA64_OP_TF, IA64_OP_THASH, IA64_OP_TNAT,
	IA64_OP_TPA, IA64_OP_TTAG,
	IA64_OP_UNPACK1, IA64_OP_UNPACK2, IA64_OP_UNPACK4,
	IA64_OP_VMSW,
	IA64_OP_XCHG1, IA64_OP_XCHG2, IA64_OP_XCHG4, IA64_OP_XCHG8, IA64_OP_XMA,
	IA64_OP_XOR,
	IA64_OP_ZXT1, IA64_OP_ZXT2, IA64_OP_ZXT4,
	/* Additional opcodes used only internally. */
	IA64_ADDITIONAL_OPCODES
};

/* Instruction. */
struct ia64_inst {
	uint64_t		i_bits;
	struct ia64_oper	i_oper[7];
	struct ia64_cmpltr	i_cmpltr[5];
	enum ia64_fmt		i_format;
	enum ia64_op		i_op;
	int			i_ncmpltrs;
	int			i_srcidx;
};

struct ia64_bundle {
	const char		*b_templ;
	struct ia64_inst	b_inst[3];
};

/* Functional units. */
enum ia64_unit {
	IA64_UNIT_NONE,
	IA64_UNIT_A = 0x0100,	/* A unit. */
	IA64_UNIT_B = 0x0200,	/* B unit. */
	IA64_UNIT_F = 0x0300,	/* F unit. */
	IA64_UNIT_I = 0x0400,	/* I unit. */
	IA64_UNIT_M = 0x0500,	/* M unit. */
	IA64_UNIT_X = 0x0600	/* X unit. */
};

#ifdef _IA64_DISAS_INT_H_
int ia64_extract(enum ia64_op, enum ia64_fmt, uint64_t, struct ia64_bundle *,
    int);
#endif

#ifdef __cplusplus
extern "C" {
#endif

int ia64_decode(const void *ip, struct ia64_bundle *);
#if 0
void ia64_completer(const struct ia64_cmpltr *, char *);
void ia64_mnemonic(const enum ia64_op, char *);
void ia64_operand(const struct ia64_oper *, char *, uint64_t);
void ia64_print_bundle(const struct ia64_bundle *, uint64_t);
void ia64_print_inst(const struct ia64_bundle *, int, uint64_t);
#endif
#ifdef __cplusplus
};
#endif

#endif /* _IA64_DISAS_H_ */