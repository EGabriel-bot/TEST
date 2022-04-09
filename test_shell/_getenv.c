#include "main.h"

char *_getenv(char *name, char *envp[])
{
	char *buffy, *pathy;
	int i = 0;

	while (envp[i] != NULL)
	{
		buffy = strtok(envp[i],"=");
		if (strcmp(buffy, name) == 0)
		{
			pathy = strtok(NULL, "=");
			return (pathy);
		}
		i++;
	}
}

/* int main (int ac, char *av[], char *envp[]) */
/* { */
/* 	printf("Andy, write now\n%s", _getenv("SHELL", envp)); */
/* 	return (0); */
/* } */
