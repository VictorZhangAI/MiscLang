#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

void write_to_file(const char *filename, const char *message)
{
	int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if(fd < 0)
	{
		perror("Failed to open file");
		exit(1);
	}

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	fcntl(fd, F_SETLKW, &lock);

	dprintf(fd, "Process %d: %s\n", getpid(), message);
	sleep(1);

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);

	close(fd);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: flock [filename]\n");
		return 1;
	}
	const char *filename = argv[1];

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Failed to fork");
		return 1;
	}
	else if(pid == 0)
	{
		write_to_file(filename, "Hello from child process!");
		exit(0);
	}

	write_to_file(filename, "Hello from parent process!");

	wait(NULL);
	return 0;
}
