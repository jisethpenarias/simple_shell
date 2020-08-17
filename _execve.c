#include "simple_shell.h"

/**
 * _execve - Execute a command.
 * @executableDir: Directory executable pointer.
 * @commands: Command to execute.
 * @env: Environment variable.
 *
 * Return: 0 on success.
 */

int _execve(char *executableDir, char **commands, char **env)
{
	(void) env;
	execve(executableDir, commands, NULL);

	return (0);
}
