#include "main.h"
int main(__attribute__((unused))int argc,__attribute__((unused)) char *argv[], char *envp[])
{
	int (*f)(char *, char **, char **);
	char **input, *lineptr = NULL, *path, *command_path;
	size_t n;

	while (1)
	{
		write(1,"JABS$ ", 6);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			break;
		}
		path = _getenv("PATH",envp);
		input = tokenizer(lineptr, " \n");
		command_path = commander(path, input[0]);
		f = router(input, command_path);
		f(command_path, input, envp);
	}
	return (0);
}
