#include "main.h"

char *commander(char* path, char* input)
{
	char **dir;
	int i;
	char *command, *temp;
	char churger[300];
	char slash[77] = "/";
	dir = tokenizer(path, ":");

	temp = strcat(slash, input);

	struct stat info;

	for (i = 0; dir[i] != NULL; i++)
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

/* int main(int argc, char* argv[], char* envp[]) */
/* { */
/* 	/1* char **test; *1/ */
/* 	char* path = _getenv("PATH", envp); */
/* 	/1* test = malloc(sizeof(test)); *1/ */
/* 	char *command = commander(path, argv[1]); */
/* 	/1* test[1] = argv[2]; *1/ */

/* 	/1* if(execve(test[0], test, envp)) *1/ */
/* 	/1* { *1/ */
/* 	/1* 	perror("execve"); *1/ */
/* 	/1* 	exit(EXIT_FAILURE); *1/ */
/* 	/1* } *1/ */
/* 	printf("%s\n", command); */
/* 	/1* write(1, command, 12); *1/ */
/* 	putchar ('\n'); */
/* 	return (0); */
/* } */
