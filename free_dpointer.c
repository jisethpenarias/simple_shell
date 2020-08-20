#include "simple_shell.h"

/**
 * free_dpointer - Liberation of double pointer.
 * @command: Double pointer.
 *
 * Return: Nothing.
 */

void free_dpointer(char **command)
{

	int i = 0;

	while (command && command[i])
	{
		free(command[i]);
		i++;
	}
	free(command);
}
