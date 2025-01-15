#include"vm/headers.h"
#include"vm/machine.h"

enum
{
	Num = 128,
	Fun,
	Sys,
	Glo,
	Loc,
	Id,
	Char,
	Else,
	Enum,
	If,
	Int,
	Return,
	Sizeof,
	While,
	Assign,
	Cond,
	Lor,
	Lan,
	Or,
	Xor,
	And,
	Eq,
	Ne,
	Lt,
	Gt,
	Le,
	Ge,
	Shl,
	Shr,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Inc,
	Dec,
	Brak
};

int token_val;
int *current_id, *symbols;

enum
{
	Token,
	Hash,
	Name,
	Type,
	Class,
	Value,
	BType,
	BClass,
	BValue,
	IdSize
};

void next()
{
	char *last_pos;
	int hash;

	while(token = *src)
	{
		++src;
		if(token == '\n') ++line;
		else if(token == '#')
		{
			while(*src != 0 && *src != '\n')
			{
				src++;
			}
		}
		else if((token >= 'a' && token <= 'z')
		     || (token >= 'A' && token <= 'Z')
		     || (token == '_'))
		{
			last_pos = src - 1;
			hash = token;
			while((*src >= 'a' && *src <= 'z')
			   || (*src >= 'A' && *src <= 'Z')
			   || (*src >= '0' && *src <= '9')
			   || (*src == '_'))
			{
				hash = hash * 147 + *src;
				src++;
			}
			current_id = symbols;
			while(current_id[Token])
			{
				if(current_id[Hash] == hash
				&& !memcmp((char *)current_id[Name], last_pos, src - last_pos))
				{
					token = current_id[Token];
					return;
				}
				current_id = current_id + IdSize;
			}
			current_id[Name] = (int)last_pos;
			current_id[Hash] = hash;
			token = current_id[Token] = Id;
		}
	}

	return;
}

void expression(int level)
{

}

void program()
{
	next();
	while(token > 0)
	{
		printf("token is: %c\n", token);
		next();
	}
}

int eval()
{
	int op, *tmp;

	while(1)
	{
		op = *pc++;
		if(op == IMM){ ax = *pc++; }
		else if(op == LC){ ax = *(char *)ax; }
		else if(op == LI){ ax = *(int *)ax; }
		else if(op == SC){ ax = *(char *)*sp++ = ax; }
		else if(op == SI){ *(int *)*sp++ = ax; }
		else if(op == PUSH){ *--sp = ax; }
		else if(op == JMP){ pc = (int *)*pc; }
		else if(op == JZ){ pc = ax ? pc + 1 : (int *)*pc; }
		else if(op == JNZ){ pc = ax ? (int *)*pc : pc + 1; }
		else if(op == CALL){ *--sp = (int)(pc + 1); pc = (int *)*pc; }
		else if(op == ENT){ *--sp = (int)bp; bp = sp; sp = sp - *pc++; }
		else if(op == ADJ){ sp = sp + *pc++; }
		else if(op == LEV){ sp = bp; bp = (int *)sp++; pc = (int *)*sp++; }
		else if(op == LEA){ ax = (int)(bp + *pc++); }
		else if(op == OR)  ax = *sp++ | ax;
		else if(op == XOR) ax = *sp++ ^ ax;
		else if(op == AND) ax = *sp++ & ax;
		else if(op == EQ)  ax = *sp++ == ax;
		else if(op == NE)  ax = *sp++ != ax;
		else if(op == LT)  ax = *sp++ < ax;
		else if(op == LE)  ax = *sp++ <= ax;
		else if(op == GT)  ax = *sp++ >  ax;
		else if(op == GE)  ax = *sp++ >= ax;
		else if(op == SHL) ax = *sp++ << ax;
		else if(op == SHR) ax = *sp++ >> ax;
		else if(op == ADD) ax = *sp++ + ax;
		else if(op == SUB) ax = *sp++ - ax;
		else if(op == MUL) ax = *sp++ * ax;
		else if(op == DIV) ax = *sp++ / ax;
		else if(op == MOD) ax = *sp++ % ax;
		else if(op == EXIT){ printf("exit(%d)\n", *sp); return *sp; }
		else if(op == OPEN){ ax = open((char *)sp[1], sp[0]); }
		else if(op == CLOS){ ax = close(*sp); }
		else if(op == READ){ ax = read(sp[2], (char *)sp[1], *sp); }
		else if(op == PRTF){ tmp = sp + pc[1]; ax = printf((char*)tmp[-1], tmp[-2], tmp[-3],
								  tmp[-4], tmp[-5], tmp[-6]); }
		else if(op == MALC){ ax = (int)malloc(*sp); }
		else if(op == MSET){ ax = (int)memset((char*)sp[2], sp[1], *sp); }
		else if(op == MCMP){ ax = memcmp((char *)sp[2], (char *)sp[1], *sp); }
		else
		{
			printf("unknown instruction: %d\n", op);
			return -1;
		}
	}

	return 0;
}

int main(int argc, char **argv)
{
	int i, fd;

	argc--;
	argv++;

	poolsize = 256 * 1024;
	line = 1;

	if((fd = open(*argv, 0)) < 0)
	{
		printf("Error: Could not open(%s)\n", *argv);
		return -1;
	}

	if(!(src = old_src = malloc(poolsize)))
	{
		printf("Error: Could not malloc (%d) for source area\n", poolsize);
		return -1;
	}

	if((i = read(fd, src, poolsize-1)) <= 0)
	{
		printf("read() returned %d\n", i);
		return -1;
	}

	src[i] = 0;
	close(fd);
	
	if(!(text = old_text = malloc(poolsize)))
	{
		printf("Could not malloc(%d) for text area\n", poolsize);
		return -1;
	}

	if(!(data = malloc(poolsize)))
	{
		printf("Could not malloc(%d) for data area\n", poolsize);
		return -1;
	}

	if(!(stack = malloc(poolsize)))
	{
		printf("Could not malloc(%d) for stack area\n", poolsize);
		return -1;
	}

	memset(text, 0, poolsize);
	memset(data, 0, poolsize);
	memset(stack, 0, poolsize);

	bp = sp = (int *)((int)stack + poolsize);
	ax = 0;

	i = 0;
	text[i++] = IMM;
	text[i++] = 10;
	text[i++] = PUSH;
	text[i++] = IMM;
	text[i++] = 20;
	text[i++] = ADD;
	text[i++] = PUSH;
	text[i++] = EXIT;
	pc = text;

	program();

	return eval();
}
