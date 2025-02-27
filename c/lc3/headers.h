#ifndef __HEADERS_H__
#define __HEADERS_H__

#include<stdio.h>
#include<stdint.h>
#include<signal.h>
#ifdef __linux__

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/termios.h>
#include<sys/mman.h>

#elif defined(_WIN32)
#include<Windows.h>
#include<conio.h>

#else
#error "Platform Unsupported"

#endif

#define MEMORY_MAX (1 << 16)

enum
{
	R_R0 = 0,
	R_R1,
	R_R2,
	R_R3,
	R_R4,
	R_R5,
	R_R6,
	R_R7,
	R_PC,
	R_COND,
	R_COUNT
};

enum
{
	OP_BR = 0,
	OP_ADD,
	OP_LD,
	OP_ST,
	OP_JSR,
	OP_AND,
	OP_LDR,
	OP_STR,
	OP_RTI,
	OP_NOT,
	OP_LDI,
	OP_STI,
	OP_JMP,
	OP_RES,
	OP_LEA,
	OP_TRAP
};

#define PC_START 0x3000

enum
{
	FL_POS = 1 << 0,
	FL_ZRO = 1 << 1,
	FL_NEG = 1 << 2,
};

#endif
