#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	char *s;
	unsigned long i;

	s = strdup("VZstless");
	if(s == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return EXIT_FAILURE;
	}
	i = 0;
	while(s)
	{
		printf("[%lu] %s (%p)\n", i, s, (void *)s);
		sleep(1);
		i++;
	}
	return EXIT_SUCCESS;
}
