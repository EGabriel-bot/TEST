#include "main.h"

/**
 * _strlen - length of a string
 *@s: pointer to some variable
 *
 * Return: Return the length of a string
 */
int _strlen(char *s)
{
	int charCount = 0;

	while (s[charCount] != '\0')
	{
		charCount++;
	}

	return (charCount);
}
