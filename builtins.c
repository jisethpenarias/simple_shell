#include "simple_shell.h"

/**
 * builtins - Check for builtins on our shell.
 * @firstToken: First token sended for verify buildtin related.
 *
 * Return: Status or 1 if it fail.
 */

int builtins(char *firstToken)
{
	int i;
	int status = 0;

	builtins_t built[] = {
		{"env", _print_env},
		{"exit", NULL},
		{NULL, NULL}
	};

	i = 0;

	while (built[i].name != NULL)
	{
		if (strcmp(firstToken, built[i].name) == 0)
		{
			status = (built[i].fun)();
			return (status);
		}
		i++;
	}
	return (1);
}
