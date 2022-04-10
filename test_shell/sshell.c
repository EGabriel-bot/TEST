#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main(__attribute__((unused))int argc,__attribute__((unused)) char *argv[], char *envp[])
{
	pid_t pid;
	char **command, *tok, *lineptr = NULL;
	size_t i, n;
	int status;
	char *path;
	char *string;

	while (1)
	{
		write(1,"JABS$ ", 6);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			break;
		}
		fflush(NULL);
		path = _getenv("PATH",envp);
		command = tokenizer(lineptr, " \n");
		command = command + 1;
		string = commander(path, command[0]);
//		write(1, string, 30);
		pid = fork();
		if (pid == 0)
		{
			_putchar('\n');
			if (execve(string, command, envp))
			{
				free(lineptr);
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		if (pid > 0)
		{
			wait(&status);
		}
	}
	_putchar('\n');
	free(lineptr);
	exit(status);
}
