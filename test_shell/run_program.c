#include "main.h"

/**
 * run_program - executes a program that exists in PATH
 * @command_path - full pathname of program file
 * input: double pointer to user input
 *
 * Return: integer value
 */
int run_program(char *command_path, char **input, char **envp)
{
	int tmp, status;

	tmp = fork();
	if (tmp == 0)
	{
		execve(command_path, input, envp);
	}
	if (tmp > 0)
	{
		wait(&status);
	}

	return (0);
}
