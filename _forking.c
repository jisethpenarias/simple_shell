#include "simple_shell.h"

/**
 * forking - Create child process.
 * @executableDir: Directory executable pointer.
 * @commands: Command to execute.
 *
 * Return: 0 on success.
 */

int forking(char *executableDir, char **commands)
{
	pid_t pid_child;
	int status;
	char error_info[100];
	int i;


	pid_child = fork();
	if (pid_child == -1)
		return (-1);

	if (pid_child == 0 && execve(executableDir, commands, NULL) == -1)
	{
		sprintf(error_info, "hsh: %s: not found\n", *commands);
		write(2, error_info, _strlen(error_info));
		exit(1);
	}
	else
	{
		pid_child = wait(&status);
		if (WIFEXITED(status))
			return (status);
	}

	return (0);
}
