#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenizer - separates a string into an array of strings using delimiters
 * @string: string to be separated
 * @delim: string where each character is a delimiter
 *
 * Return: pointer to pointer to strings.
 *
 * **IMPORTANT NOTE**	Must free return using tokenizer_free() function.
 *			Normal free() function will cause memory leaks.
 */
char **tokenizer(char *string, char *delim)
{
	char **tokens, *str, *tmp;
	int i;

	/*create copy of string to prevent corrupting input*/
	str = malloc(strlen(string) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	str = strcpy(str, string);
	tmp = str;

	/*create tokens from string*/
	tokens = malloc(2 * sizeof(tokens));
	if (tokens == NULL)
	{
		return (NULL);
	}
	tokens[0] = strtok(str, delim);
	i = 0;
	while (tokens[i] != NULL)
	{
		i++;
		tokens = realloc(tokens, (i + 2) * sizeof(tokens));
		if (tokens == NULL)
		{
			free(tokens);
			tokens = NULL;
			return (NULL);
		}
		tokens[i] = strtok(NULL, delim);
	}

	/*Add pointer to copy at end for freeing later*/
	tokens[i + 1] = tmp;

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
	int i;

	if (token != NULL)
	{
		i = 0;
		while (token[i] != NULL)
		{
			i++;
		}
		free(token[i + 1]);
		token[i + 1] = NULL;
		free(token);
		token = NULL;
	}
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
   lineptr = NULL;
   return (0);
   }
 */
