#include "simple_shell.h"

/**
 *hsh- method emulating sh
 *@av: values
 *@env: environment
 * Return: int
 */

int hsh(char **av, char **env)
{
	char *line = NULL, *path, *cmdPath, **cmdTokens;
	size_t len;
	int read = 0, status_builtins, mode = 1, exit_stat = 0;
	(void)av;

	isatty(STDIN_FILENO) == 0 ? mode = 0 : mode;
	while (1)
	{
		mode == 1 ? write(STDIN_FILENO, "$ ", 2) : mode;
		read = getline(&line, &len, stdin);
		if (read == EOF || _strncmp(line, "exit\n", 4) == 0)
		{
			free(line);
			if (read == EOF && isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (exit_stat);
		}
		else
		{
			if (read >= 1 && have_space(line))
			{
				cmdTokens = tokenizer(line);
				status_builtins = builtins(cmdTokens[0]);
				if (status_builtins == -1)
					exit(1);
				if (status_builtins == 0)
					continue;
				path = _getenv("PATH", env);
				if (path == NULL)
					cmdPath = cmdTokens[0];
				else
					cmdPath = _which(path, cmdTokens[0]);
				exit_stat = forking(cmdPath, cmdTokens);
				free(path);
				if (_strcmp(cmdPath, cmdTokens[0]) != 0)
					free(cmdPath);
				free_dpointer(cmdTokens);
			}
		}
	}
}

/**
 *have_space - this function validates characters other than spacesh.
 *@command: characters to validate.
 *
 * Return: 0
 */

int have_space(char *command)
{
	unsigned int i;

	for (i = 0; i < _strlen(command) - 1; i++)
	{
		if (command[i] != ' ')
		{
			return (1);
		}
	}
	return (0);
}
