#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "worm_simulation"
#define COPY_SUFFIX "_copy"

void replicate()
{
	char new_filename[256];
	snprintf(new_filename, sizeof(new_filename), "%s%s", FILENAME, COPY_SUFFIX);

	FILE *src = fopen(FILENAME, "rb");
	if(!src)
	{
		perror("Opening source file");
		return;
	}

	FILE *dest = fopen(new_filename, "wb");
	if(!dest)
	{
		perror("Error creating copy");
		fclose(src);
		return;
	}

	char buffer[1024];
	size_t bytes;
	while((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
	{
		fwrite(buffer, 1, bytes, dest);
	}

	fclose(src);
	fclose(dest);
	printf("File replicated as %s\n", new_filename);
}

int main()
{
	printf("Simulating a safe worm...\n");
	replicate();
	return 0;
}
