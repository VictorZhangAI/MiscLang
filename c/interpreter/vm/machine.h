#ifndef __MACHINE_H__
#define __MACHINE_H__

int token;
char *src, *old_src;
int poolsize;
int line;

int *text,
    *old_text,
    *stack;

char *data;

int *pc, *bp, *sp, ax, cycle;

enum {
	LEA,
	IMM,
	JMP,
	CALL,
	JZ,
	JNZ,
	ENT,
	ADJ,
	LEV,
	LI,
	LC,
	SI,
	SC,
	PUSH,
	OR,
	XOR,
	AND,
	EQ,
	NE,
	LT,
	GT,
	LE,
	GE,
	SHL,
	SHR,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	OPEN,
	READ,
	CLOS,
	PRTF,
	MALC,
	MSET,
	MCMP,
	EXIT
};

#endif
