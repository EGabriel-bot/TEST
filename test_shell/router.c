#include "main.h"

/**
 * router - routes data to appropriate function
 * @input: double pointer to char (tokenized user input)
 * @command_path: pointer to char
 *
 * Return: pointer to function
 */
int (*router(char **input, char *command_path))(char*, char**, char**)
{
	(void)command_path;

	if(strcmp(input[0], "exit") == 0)
	{
		return (NULL);
	}
	else if(strcmp(input[0], "env") == 0)
	{
		return (NULL);
	}
	else
	{
		return(run_program);
	}
}


/**
 * main - test router
 *
 * Return: always 0
 */
/*
int main(int argc, char **argv, char **envp)
{
	int (*f)(char *, char **, char **);

	(void)argc;

	argv++;

	f = router(argv, "not used");

	f("/usr/bin/ls", argv, envp);

	return(0);
}
*/
