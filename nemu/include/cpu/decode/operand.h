#ifndef __OPERAND_H__
#define __OPERAND_H__

enum { OP_TYPE_REG, OP_TYPE_MEM, OP_TYPE_IMM };

#define OP_STR_SIZE 40


// 操作数
typedef struct {
	uint32_t type;				// 类型
	size_t size;				// 大小
	union {
		uint32_t reg;			// 寄存器
		struct {
			swaddr_t addr;		// 地址
			uint8_t sregister;	// 
		};
		uint32_t imm;
		int32_t simm;
	};
	uint32_t val;
	char str[OP_STR_SIZE];
} Operand;



typedef struct {
	uint32_t opcode;
	bool is_operand_size_16;
	Operand src, dest, src2;
} Operands;



#endif
