#include "simple_shell.h"

int forking(char *executableDir, char **commands)
{
	pid_t value;
	int status;

	value = fork();
	if (value == -1)
		return (1);

	if (value == 0)
	{
		if (_execve(executableDir, commands, NULL) == -1)
			exit(1);
	}
	else
	{
		wait(&status);
		return (0);
	}

	return (0);
}
