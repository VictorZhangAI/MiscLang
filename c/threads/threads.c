#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>

void *thread_function(void *arg)
{
	printf("Thread: Hello from thread!\n");
	return NULL;
}

int main()
{
	pthread_t thread;
	if(pthread_create(&thread, NULL, thread_function, NULL) != 0)
	{
		perror("Create thread");
		return 1;
	}

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Fork");
		return 1;
	}
	else if(pid == 0)
	{
		printf("Process: Hello from child process!\n");
		exit(0);
	}

	pthread_join(thread, NULL);
	wait(NULL);

	printf("Main: all tasks completed!\n");
	return 0;
}
