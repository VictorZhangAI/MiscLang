#ifndef __MEMALLOC_H__
#define __MEMALLOC_H__

#include<stddef.h>

typedef char ALIGN[16];

typedef union header
{
	struct
	{
		size_t size;
		unsigned is_free;
		union header *next;
	}s;
	ALIGN stub;
} header_t;

void* malloc(size_t size);
void free(void *block);
void *calloc(size_t num, size_t nsize);
void *realloc(void *block, size_t size);

#endif
