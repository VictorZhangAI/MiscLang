#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int main()
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL};

	if(posix_spawn(&pid, "/bin/ls", NULL, NULL, argv, environ) == 0)
	{
		int status;
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("posix_spawn failed");
		return 1;
	}
	return 0;
}
