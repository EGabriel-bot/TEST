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
	char *command[16], *tok, *lineptr = NULL;
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
		path = _getenv("PATH",envp);
		tok = strtok(lineptr, " \n");
		string = commander(path, tok);
		tok = string;
		for (i = 0; i < 16 && tok != NULL; i++)
		{
			command[i] = tok;
			tok = strtok(NULL, " \n");
		}
		command[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			write(1, command[0], 30);
			_putchar('\n');
			if (execve(command[0], command, envp))
			{
				free(string);
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
