#include "main.h"


/**
 * commander - builds command pathname if it exists
 * @path: pointer to char (PATH string from environment)
 * @input: pointer to char (command name string)
 *
 * Return: pointer to char (full pathname of file)
 *
 * **IMPORTANT NOTE**	Return pointer must be freed
 */
char *commander(char *path, char *input)
{
	char **dir;
	int i;
	char *command, *temp;
	struct stat info;

	dir = tokenizer(path, ":");

	temp = malloc(strlen(input) + 2);
	temp = strcpy(temp, "/");
	temp = strcat(temp, input);
	temp = strcat(temp, "\0");

	command = malloc(1);
	for (i = 0; dir[i] != NULL; i++)
	{
		command = realloc(command, strlen(dir[i]) + strlen(temp) + 1);
		command = strcpy(command, dir[i]);
		command = strcat(command, temp);
		if (stat(command, &info) == 0)
		{
			free(temp);
			tokenizer_free(dir);
			return (command);
		}
	}

	free(temp);
	tokenizer_free(dir);
	return (input);
}

/*
int main(int argc, char *argv[], char *envp[])
{
	char *path = _getenv("PATH", envp);

	char *command = commander(path, argv[1]);

	(void)argc;

	printf("%s\n", command);

	fflush(NULL);

	free(path);
	free(command);

	return (0);
}
*/
