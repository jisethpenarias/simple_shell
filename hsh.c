#include "simple_shell.h"

int main(void)
{

	char *line = NULL;
        size_t len;
	char **commandTokens;
	int status_builtins;
	char *path;
	char *commandPath;

	while (1)
	{
		write (STDIN_FILENO, "$ ", 2);

		if(getline(&line, &len, stdin) == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			free(line);
			exit(0);
		}

		commandTokens = tokenizer(line);
		status_builtins = builtins(commandTokens[0]);
		if(status_builtins == -1 || status_builtins == 0)
		{
			free(line);
			free(commandTokens);
		}
		if(status_builtins == -1)
			exit(1);
		if(status_builtins == 0)
			continue;

		path = _getenv("PATH");
		commandPath = _which(path, commandTokens[0]);
		forking(commandPath, commandTokens);

		/*free(line);
		free(commandTokens);
		free(commandPath);
		free(path);*/
	}

}
