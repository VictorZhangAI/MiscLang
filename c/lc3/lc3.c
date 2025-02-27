#include"headers.h"

uint16_t reg[R_COUNT];

uint16_t memory[MEMORY_MAX];

uint16_t sign_extend(uint16_t x, int bit_count)
{
	if((x >> (bit_count - 1)) & 1)
	{
		x |= (0xFFFF << bit_count);
	}
	return x;
}

void update_flags(uint16_t r)
{
	if(reg[r] == 0)
	{
		reg[R_COND] = FL_ZERO;
	}
	else if(reg[r] >> 15)
	{
		reg[R_COND] = FL_NEG;
	}
	else
	{
		reg[R_COND] = FL_POS;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("lc3 [image-file1] ...\n");
		exit(2);
	}

	for(int i = 1; i < argc; i++)
	{
		if(!read_image(argv[i]))
		{
			printf("failed to load image: %s\n", argv[i]);
			exit(1);
		}
	}
	//setup
	
	reg[R_COND] = PC_START;

	int running = 1;
	while(running)
	{
		uint16_t instr = mem_read(reg[R_PC]++);
		uint16_t op = instr >> 12;

		switch (op)
		{
			case OP_ADD:
				//ADD
				break;
			case OP_AND:
				//AND
				break;
			case OP_NOT:
				//NOT
				break;
			case OP_BR:
				//BR
				break;
			case OP_JMP:
				//JMP
				break;
			case OP_JSR:
				//JSR
				break;
			case OP_LD:
				//LD
				break;
			case OP_LDI:
				//LDI
				break;
			case OP_LDR:
				//LDR
				break;
			case OP_LEA:
				//LEA
				break;
			case OP_ST:
				//ST
				break;
			case OP_STI:
				//STI
				break;
			case OP_STR:
				//STR
				break;
			case OP_TRAP:
				//TRAP
				break;
			case OP_RES:
			case OP_RTI:
			default:
				//BAD_OPCODE
				break;
			
		}
	}
	//shutdown
	return 0;
}
