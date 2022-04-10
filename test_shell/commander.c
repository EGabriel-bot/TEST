#include "main.h"

char *commander(char* path, char* input)
{
	char **dir;
	int i;
	char *command, *temp;
	char churger[300];
	char slash[77] = "/";
	dir = tokenizer(path, ":");

	temp = malloc(100);
	temp = strcat(slash, input);
	temp = strcat(temp, "\0");

	struct stat info;

	for (i = 1; dir[i] != NULL; i++)
	{
		strcpy(churger, dir[i]);
		command = strcat(churger, temp);
		if (stat(command, &info) == 0)
		{
			free(dir);
			return (command);
		}
	}
	free(dir);
	return (input);
}
/*
int main(int argc, char* argv[], char* envp[])
 {
 	char* path = _getenv("PATH", envp);

 	char *command = commander(path, argv[1]);

	printf("Main: %s\n", command);

	fflush(NULL);
 	return (0); 
 }*/
