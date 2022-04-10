#include "main.h"

/**
 * _getenv - gets a string variable value from the environment
 * @name: desired variable name
 * @envp: inherited environment
 *
 * Return: pointer to char (string variable)
 */
char *_getenv(char *name, char *envp[])
{
	char **line, **line_tokens, *var;
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		line = tokenizer(envp[i], "=");
		if (strcmp(line[1], name) == 0)
		{
			var = malloc(strlen(line[2]) + 1);
			var = strcpy(var, line[2]);
			tokenizer_free(line);
			return (var);
		}
		tokenizer_free(line);
		i++;
	}
}


/*
int main (int ac, char *av[], char *envp[])
{
	char *result = _getenv("PATH", envp);
 	printf("%s\n", result);
	free(result);
 	return (0); 
}
*/
