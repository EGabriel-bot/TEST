#include "main.h"

char* commander(char* path, char* input)
{
	char** dir;
	int i;
	char *command, *temp;
	char churger[300];
	char slash[77] = "/";
	command = malloc(120);
	temp = malloc(120);
	dir = tokenizer(path, ":");

	temp = strcat(slash, input);

	struct stat info;

	for (i = 0; dir[i] != NULL; i++)
	{
		strcpy(churger, dir[i]);
		command = strcat(churger, temp);
		/*printf("%s\n", command);*/

		if (stat(command, &info) == 0)
			return (command);
	}
	return (input);
}

int main(int argc, char* argv[], char* envp[])
{
	char* path = _getenv("PATH", envp);
	char* command = commander(path, argv[1]);

	/* printf("%s\n", command); */
	write(1, command, 20);
	putchar ('\n');
	return (0);
}
