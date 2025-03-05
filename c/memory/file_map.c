#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd = open("test.txt", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return 1;
	}

	struct stat st;
	fstat(fd, &st);

	char *map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(map == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return 1;
	}
	printf("file content: %s\n", map);
	strncpy(map, "Hello, mmap!", 12);
	munmap(map, st.st_size);
	close(fd);
	return 0;
}
