#include "simple_shell.h"

/**
 *_print_env - Print environment variables.
 *
 *Return: Return 0,
 */

int _print_env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

