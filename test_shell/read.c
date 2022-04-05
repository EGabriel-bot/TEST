#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	size_t buffsize = 0;

	_putchar ('$');
	_putchar (' ');
	getline(&buffer, &buffsize,stdin);
	write(1, buffer, buffsize);

	free(buffer);
	return (0);
}
