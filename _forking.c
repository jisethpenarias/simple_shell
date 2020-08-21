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
	int status, exit_st;
	char error_info[100];
	struct stat str;

	if (stat(executableDir, &str) == 0)
	{
		pid_child = fork();
		if (pid_child == 0)
		{
			execve(executableDir, commands, NULL);
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_st = WEXITSTATUS(status);
			return (exit_st);
		}
	}
	else
	{
		sprintf(error_info, "hsh: %s: not found\n", *commands);
		write(2, error_info, _strlen(error_info));
		return (127);
	}
	return (0);
}
