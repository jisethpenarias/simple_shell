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
	pid_t value;
	int status;
	char error_info[100];
	int i;

	value = fork();
	if (value == -1)
		return (-1);

	i = 0;
	while(commands[i])
	{
		printf("%s\n", commands[i]);
		i++;
	}

	if (value == 0 && execve(executableDir, commands, NULL) == -1)
	{
		sprintf(error_info, "hsh: %s: not found\n", *commands);
		write(2, error_info, _strlen(error_info));
		exit(1);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
