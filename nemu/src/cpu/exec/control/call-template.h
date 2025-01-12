#include "cpu/exec/template-start.h"

#define instr call

make_helper (concat(call_i_, SUFFIX))
{
	int len = concat(decode_i_, SUFFIX) (eip + 1);
	reg_l (R_ESP) -= DATA_BYTE;
	swaddr_write (reg_l (R_ESP) , 4 , cpu.eip + len, SS);
	DATA_TYPE_S displacement = op_src->val;
	print_asm("call %x", cpu.eip + 1 + len + displacement);
	cpu.eip += displacement;
	return len + 1;
}

make_helper(concat(call_rm_, SUFFIX))
{
	int len = concat(decode_rm_, SUFFIX)(eip + 1);
	reg_l(R_ESP) -= DATA_BYTE;
	MEM_W(reg_l(R_ESP), cpu.eip + len, SS);
	print_asm("call %x", op_src->val);
	cpu.eip = op_src->val - len - 1;
	return len + 1;
}


#include "cpu/exec/template-end.h"
