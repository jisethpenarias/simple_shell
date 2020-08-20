#include "simple_shell.h"

/**
 *
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
