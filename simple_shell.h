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

#define MAX_BUFFER_SIZE 1024
#define SPLIT_STRING "\n\t\r\a "

extern char **environ;

/**
 * struct builtins_s - print type with print function builtins
 * @name: Print name.
 * @fun:Print function.
 */

typedef struct builtins_s
{
	char *name;
	int (*fun)();
} builtins_t;

int _exit_hsh(void);
int hsh(char **av, char **env);
int exec_noInteracti(char **av);
int have_space(char *command);
char *_which(char *pathVariable, char *commandSearched);
char *_getenv(char *variable, char **env);
int builtins(char *firstToken);
int forking(char *executableDir, char **commands);
int _print_env(void);
void free_dpointer(char **command);
void _signal_handle(int singint);

/*funciones de string*/

int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **tokenizer(char *line);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
