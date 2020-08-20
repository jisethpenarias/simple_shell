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
	(void)env;

	isatty(STDIN_FILENO) == 0 ? mode = 0 : mode;
	while (1)
	{
		mode == 1 ? write(STDIN_FILENO, "$ ", 2) : mode;
		read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			free(line), write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		else
		{
			if (read > 1)
			{
				commandTokens = tokenizer(line);
				status_builtins = builtins(commandTokens[0]);
				if (status_builtins == -1)
					exit(1);
				if (status_builtins == 0)
					continue;
				path = _getenv();
				if (path == NULL)
					commandPath = commandTokens[0];
				else
					commandPath = _which(path, commandTokens[0]);

				forking(commandPath, commandTokens);
				free(commandTokens);
				free(path);
			}
		}
	}
}
