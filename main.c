#include "simple_shell.h"

/**
 * main  - shell start.
 * @ac : Directory executable pointer.
 * @av : Command to execute.
 * @env : Environment variable.
 *
 * Return: process value.
 */

int main(int ac, char *av[], char **env)
{
	int runing = 0;
	/*unsigned int executionCount = 1;*/

	signal(SIGINT, _signal_handle);

	if (ac > 1)
		exec_noInteracti(av);
	else
		runing = hsh(av, env);
	return (runing);
}
