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
		reg[R_COND] = FL_ZRO;
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
				{
					uint16_t r0 = (instr >> 9) & 0x7;
					uint16_t r1 = (instr >> 6) & 0x7;
					uint16_t imm_flag = (instr >> 5) & 0x1;

					if(imm_flag)
					{
						uint16_t imm5 = sign_extend(instr & 0x1F, 5);
						reg[r0] = reg[r1] + imm5;
					}
					else
					{
						uint16_t r2 = instr & 0x7;
						reg[r0] = reg[r1] + reg[r2];
					}
					update_flags(r0);
				}
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
				{
					uint16_t r0 = (instr >> 9) & 0x7;
					uint16_t pc_offset = sign_extend(instr & 0x1FF, 9);
					reg[r0] = mem_read(mem_read(reg[R_PC] + pc_offset));
					update_flags(r0);
				}
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
				{
					abort();
				}
			default:
				//BAD_OPCODE
				break;
			
		}
	}
	//shutdown
	return 0;
}
