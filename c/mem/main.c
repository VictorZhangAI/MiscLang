#include"memalloc.h"
#include<stdio.h>

int main()
{
	int *p = malloc(4 * sizeof(int));
	for(int i = 0; i < 4; i++)
		p[i] = i;
	for(int i = 0; i < 4; i++)
		printf("%d\n", p[i]);
	return 0;
}
