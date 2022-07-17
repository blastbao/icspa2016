#ifndef __REG_H__
#define __REG_H__

#include "common.h"
#include "../../../lib-common/x86-inc/cpu.h"

enum { R_EAX, R_ECX, R_EDX, R_EBX, R_ESP, R_EBP, R_ESI, R_EDI };
enum { R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI };
enum { R_AL, R_CL, R_DL, R_BL, R_AH, R_CH, R_DH, R_BH };
enum { ES, CS, SS, DS, FS, GS};

/* TODO: Re-organize the `CPU_state' structure to match the register
 * encoding scheme in i386 instruction format. For example, if we
 * access cpu.gpr[3]._16, we will get the `bx' register; if we access
 * cpu.gpr[1]._8[1], we will get the 'ch' register. Hint: Use `union'.
 * For more details about the register encoding scheme, see i386 manual.
 */
typedef struct SREG {
	union {
		struct {
			uint32_t dpl: 2;
			uint32_t ti : 1;
			uint32_t index: 13;
		};
		uint16_t selector;
	};
	bool cache;
	uint32_t base;
	uint32_t limit;
} sreg;




typedef struct {
	union {

		// 分配 8 * 32(max) 大小内存，模拟 8 个通用寄存器。
		union {
			uint32_t _32;
			uint16_t _16;
			uint8_t _8[2];
		} gpr[8];


		/* Do NOT change the order of the GPRs' definitions. */
		struct {
			uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi;
			swaddr_t eip;
			union {
				struct {
					uint32_t CF: 1;
					uint32_t : 1;
					uint32_t PF: 1;
					uint32_t : 1;
					uint32_t AF: 1;
					uint32_t : 1;
					uint32_t ZF: 1;
					uint32_t SF: 1;
					uint32_t TF: 1;
					uint32_t IF: 1;
					uint32_t DF: 1;
					uint32_t OF: 1;
					uint32_t IOPL: 1;
					uint32_t NT: 1;
					uint32_t : 1;
					uint32_t RF: 1;
					uint32_t VM: 1;
					uint32_t : 14;
				};
				uint32_t eflags;
			};
		};

	};

	struct GDTR
	{
		uint32_t base_addr;
		uint16_t seg_limit;
	} gdtr, idtr;

	CR0 cr0;
	CR3 cr3;
	sreg s_reg[6];
	bool INTR;


} CPU_state;

extern CPU_state cpu;

static inline int check_reg_index(int index) {
	assert(index >= 0 && index < 8);
	return index;
}

#define reg_l(index) (cpu.gpr[check_reg_index(index)]._32)
#define reg_w(index) (cpu.gpr[check_reg_index(index)]._16)
#define reg_b(index) (cpu.gpr[check_reg_index(index) & 0x3]._8[index >> 2])
#define seg(index) (cpu.s_reg[check_reg_index(index)])

extern const char* regsl[];
extern const char* regsw[];
extern const char* regsb[];

#endif