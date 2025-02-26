#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char *s;
	
	s = strdup("VZstless");
	if(s == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return EXIT_FAILURE;
	}
	printf("%p\n", (void *)s);
	return EXIT_SUCCESS;
}
