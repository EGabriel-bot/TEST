#include "main.h"
#include <unistd.h>
#include <stdio.h>

int main(__attribute__((unused))int ac, char **av)
{
	/* char *ws = " "; */
	/* int ccount = 0; */
	
	while (*av != NULL)
	{
		write(STDOUT_FILENO, *av, _strlen(*av));
		/* write(STDOUT_FILENO, ws, 1); */
		_putchar (*av);
		_putchar ('\n');
		av++;
	}
	/* putchar ('\n'); */

	return (0);
}
