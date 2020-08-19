#include "simple_shell.h"

/**
 *tokenizer - split the line in tokens
 *@line: line received from hsh
 *
 *Return: tokens splitted
 */

char **tokenizer(char *line)
{

	char **commandTokens;
	char *command;
	int commandCount;

	commandCount = 0;

	commandTokens = (char **)malloc(sizeof(char) *
				       _strlen(line) * _strlen(line));

	if (!commandTokens)
	{
		/* print error message, or exit function*/
		return (NULL);
	}

	command = strtok(line, SPLIT_STRING);
	while (command != NULL)
	{
		commandTokens[commandCount] = command;
		command = strtok(NULL, SPLIT_STRING);
		commandCount++;
	}
	commandTokens[commandCount] = NULL;

	return (commandTokens);
}
