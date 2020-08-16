#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <fcntl.h>
#include <unistd.h>

extern char **environ;

/**
 * struct linked_path_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 */

typedef struct linked_path_s
{
	char *str_path_name;
	unsigned int len_path;
	struct path_s *next_path;
} path_t;

/**
 * struct print - print type with print function builtins
 * @name: print name.
 * @f: print function.
 */
typedef struct builtins_s
{
	char *name;
	int (*fun)(void);
} builtins_t;


ssize_t prompt();


char *_which(char *pathVariable, char *commandSearched);
int _getline(char **lineptr, size_t *size, int stream);
int _execve(char *executableDir, char **commands, char **env);

char *_getenv(char *var);

void print_dirPath (char *var);
int _print_env(void);

int builtins(char *firstToken);


int forking(char *executableDir, char **commands);

/*funciones de string*/
int _strcmp(char *s1, char *s2);
char *_strdup (char * str);
int _strlen(char *s);
#endif
