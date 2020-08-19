#include "simple_shell.h"

/**
 *hsh- method emulating sh
 *@av: values
 *@env: environment
 * Return: int
 */

int hsh(char **av, char **env)
{
	char *line == NULL, path, commandPath;
	size_t len;
	char **commandTokens;
	int status_builtins;

	/*int cleaner;*/
	int mode = 1;

	(void) av;
	(void) env;

	isatty(STDIN_FILENO) == 0 ? mode = 0 : mode;
	while (1)
	{
		mode == 1 ? write(STDIN_FILENO, "$ ", 2) : mode;
		/*cleaner = 0;*/
		if (getline(&line, &len, stdin) == EOF)
		{
			if (mode == 1)
				write(STDIN_FILENO, "\n", 1);
			free(line);
			return (0);
		}
		commandTokens = tokenizer(line);
		status_builtins = builtins(commandTokens[0]);
		if (status_builtins == -1 || status_builtins == 0)
		{
			/*free(line);*/
			/*free(commandTokens);*/
		}
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
	}
}
