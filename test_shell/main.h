#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _putchar(char c);
char *_getenv(char *name, char *envp[]);
char *_strcat(char *dest, char *src);
char **tokenizer(char *str, char *delim);
char *commander(char* path, char* input);

#endif

