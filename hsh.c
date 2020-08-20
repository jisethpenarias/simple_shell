#include "simple_shell.h"

/**
 *hsh- method emulating sh
 *@av: values
 *@env: environment
 * Return: int
 */

int hsh(char **av, char **env)
{
	char *line = NULL, *path, *commandPath;
	size_t len;
	char **commandTokens;
	int read = 0, status_builtins, mode = 1;
	(void)av;

	isatty(STDIN_FILENO) == 0 ? mode = 0 : mode;
	while (1)
	{
		mode == 1 ? write(STDIN_FILENO, "$ ", 2) : mode;
		read = getline(&line, &len, stdin);
		if (read == EOF || _strcmp(line, "exit\n") == 0)
		{
			free(line), write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		else
		{
			if (read >= 1 && have_space(line))
			{
				commandTokens = tokenizer(line);
				status_builtins = builtins(commandTokens[0]);
				if (status_builtins == -1)
					exit(1);
				if (status_builtins == 0)
					continue;
				path = _getenv("PATH", env);
				if (path == NULL)
					commandPath = commandTokens[0];
				else
					commandPath = _which(path,
							     commandTokens[0]);
				forking(commandPath, commandTokens);
				free(path);
			}
			if (commandTokens)
			{
				free_dpointer(commandTokens);
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

	for (i = 0; i < strlen(command) - 1; i++)
	{
		if (command[i] != ' ')
		{
			return (1);
		}
	}
	return (0);
}
