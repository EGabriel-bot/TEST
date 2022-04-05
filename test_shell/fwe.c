#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int test;
	int status;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	pid = fork();
	if (pid == -1)
	{
		printf("Fork failed\n");
		return (1);
	}
	if (pid == 0)
	{
		test = (execve(argv[0], argv, NULL));
		if(test == -1)
		{
			printf("Execve failed\n");
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
