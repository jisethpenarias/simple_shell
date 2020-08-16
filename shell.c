#include "simple_shell.h"

int main(void)
{

	char *commands;
	size_t sizeCommands;

	char *command;
	int commandNum;
	const char commandDelimiters[] = " \n";

	char *commandTokens[10];
	char *envp[] = {NULL};

	printf("#mini-shell$ ");

	(void) envp;
	commandNum = 0;
	commands = NULL;
	sizeCommands = 1024;
	commands = malloc(sizeCommands);
	if(getline(&commands, &sizeCommands, stdin) == -1)
	{
		printf("NO LINE");
	}

	command = strtok(commands, commandDelimiters);

	while (command != NULL)
	{
		commandTokens[commandNum] = command;
		command = strtok(NULL, commandDelimiters);
		commandNum++;
	}
	commandTokens[commandNum] = NULL;
	_execve(commandTokens, envp);
	free(commands);
	return (0);
}
