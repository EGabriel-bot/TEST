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
		lineptr = NULL;
		tok = NULL;
		path = NULL;
		string = NULL;
		for (i = 0; i <5; i++)
		{
			command[i] = NULL;
		}
		command = NULL;

		write(1,"JABS$ ", 6);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			break;
		}
		path = _getenv("PATH",envp);
		command = tokenizer(lineptr, " \n");
		write(1, "\n", 1);
		write(1, *command, 100);
		write(1, "\n", 1);
		string = commander(path, command[0]);
		write(1, "n", 1);
		write(1, string, 100);
		write(1, "\n", 1);

		pid = fork();
		if (pid == 0)
		{
			if (execve(string, command, envp))
			{
				free(command);
				free(string);
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		if (pid > 0)
		{
			free(command);
			wait(&status);
		}
	}
	_putchar('\n');
	free(command);
	free(lineptr);
	exit(status);
}
