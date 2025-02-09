#ifndef __MEMALLOC_H__
#define __MEMALLOC_H__

typedef char ALIGN[16];

union header
{
	struct
	{
		size_t size;
		unsigned is_free;
		union header *next;
	}s;
	ALIGN stub;
};
typedef union header header_t;

void* malloc(size_t size);


#endif
