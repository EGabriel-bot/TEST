#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenizer(char *str, char *delim)
{
	char **tokens;
	int i;

	tokens = malloc(sizeof(tokens));
	if (tokens == NULL)
		return (NULL);
	tokens[0] = strtok(str, delim);

	i = 0;
	while (tokens[i] != NULL)
	{
		i++;
		tokens = realloc(tokens, (i + 1) * sizeof(tokens));
		if (tokens == NULL)
		{
			free(tokens);
			return (NULL);
		}
		tokens[i] = strtok(NULL, delim);
	}

	return (tokens);
}

/*
int main(void)
{
	int i;
	char **word;
	char *lineptr;
	size_t n;

	getline(&lineptr, &n, stdin);

	word = tokenizer(lineptr, ":\n");
	i = 0;
	while (word[i] != NULL)
	{
		printf("%s\n", word[i]);
		i++;
	}

	free(lineptr);
	free(word);
	return (0);
}
*/
