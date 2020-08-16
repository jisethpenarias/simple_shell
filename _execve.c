#include "simple_shell.h"

int _execve(char *executableDir, char **commands, char **env)
{
	(void) env;
	execve(executableDir, commands, NULL);

	return(0);
}
