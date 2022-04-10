#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenizer - separates a string into an array of strings using delimiters
 * @string: string to be separated
 *    ***IMPORTANT*** string is destroyed after call to this function
 * @delim: string where each character is a delimiter
 *
 * Return: pointer to pointer to strings
 *
 * note: must free return value each time this program is called
 */
char **tokenizer(char *string, char *delim)
{
	char **tokens, *str;
	int i;

	str = malloc(strlen(string) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	str = strcpy(str, string);

	tokens = malloc(2 * sizeof(tokens));
	if (tokens == NULL)
	{
		return (NULL);
	}
	tokens[0] = str;
	tokens[1] = strtok(str, delim);

	i = 1;
	while (tokens[i] != NULL)
	{
		i++;
		tokens = realloc(tokens, (i + 1) * sizeof(tokens));
		if (tokens == NULL)
		{
			free(tokens[0]);
			free(tokens);
			return (NULL);
		}
		tokens[i] = strtok(NULL, delim);
	}

	return (tokens);
}


/**
 * tokenizer_free - frees memory created by a call of tokenizer
 * @token: the tokenized data you want to free
 *
 * Return: no return value
 */
void tokenizer_free(char **token)
{
	free(token[0]);
	free(token);
}


/**
 * main - used to test troubleshoot tokenizer function
 *
 * Return: always 0
 */
/*
int main(void)
{
	int i;
	char **word;
	char *lineptr = NULL;
	size_t n;

	getline(&lineptr, &n, stdin);

	word = tokenizer(lineptr, " \n");
	i = 0;
	while (word[i] != NULL)
	{
		printf("%s\n", word[i]);
		i++;
	}

	tokenizer_free(word);
	free(lineptr);
	return (0);
}
*/


