#include "simple_shell.h"

int main(void)
{
	/* holder for first line received on shell */
	char *line = NULL;
        size_t len;

	/*related to the command and flags splited*/
	char *commandTokens[10];
	char *command;
	int commandCount = 0;

	/*status builtin result*/
	int status_builtins;

	/*executing commands from shell*/
	char *path;
	char *commandPath;

	while (1)
	{
		write (STDIN_FILENO, "$ ", 2);

		if(getline(&line, &len, stdin) == EOF)
		{
			free(line);
			exit(0);
		}

		command = strtok(line, "\n\t\r ");
		while (commandTokens[commandCount])
		{
			commandTokens[commandCount] = command;
			command = strtok(NULL, "\n\t\r ");
			commandCount++;
		}
		/*commandTokens[commandCount] = NULL;*/
		status_builtins = builtins(commandTokens[0]);
		if(status_builtins == -1 || status_builtins == 0)
		{
			free(line);
			/*free(commandTokens);*/
		}
		if(status_builtins == -1)
		{
			exit(1);
		}
		if(status_builtins == 0)
		{
			continue;
		}

		/*si la ejecucion llega hasta aqui es por que
		 el comando recibido no esta en builtins*/
		path = _getenv("PATH");
		commandPath = _which(path, commandTokens[0]);
		/* /bin/ls */
		/*int forking(char *executableDir, char **commands)*/
		forking(commandPath, commandTokens);

                /*
		_fork; /macro...
		_free;
		*/
	}

}
