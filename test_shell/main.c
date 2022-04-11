#include "main.h"
int main(__attribute__((unused))int argc,__attribute__((unused)) char *argv[], char *envp[])
{
	int (*f)(char *, char **, char **);
	char **input, *lineptr = NULL, *path, *command_path;
	size_t n = 0;

	while (1)
	{
		write(1,"JABS$ ", 6);
		/*lineptr needs free*/
		if (getline(&lineptr, &n, stdin) == -1) 
		{
			break;
		}
		/*path needs free*/
		path = _getenv("PATH",envp);
		/*input needs tokenizer_free*/
		input = tokenizer(lineptr, " \n");

		if (strcmp(input[0], "exit") == 0)
		{
			free(lineptr);
			lineptr = NULL;
			free(path);
			path = NULL;
			tokenizer_free(input);
			exit(0);
		}

		/*command_path needs free*/
		command_path = commander(path, input[0]);
		f = router(input, command_path);
		f(command_path, input, envp);
		
		free(lineptr);
		lineptr = NULL;
		free(path);
		path = NULL;
		tokenizer_free(input);
		free(command_path);
		command_path = NULL;
	}

	return (0);
}
