#include "simple_shell.h"

/**
 *tokenizer - split the line in tokens
 *@line: line received from hsh
 *
 *Return: tokens splitted
 */

char **tokenizer(char *line)
{
	char **commandTokens = NULL;
	char *command = NULL, *buff = NULL;
	int commandCount = 0, i;

	buff = malloc(sizeof(char) * _strlen(line) + 1);
	if (buff == NULL)
		return (NULL);
	_strcpy(buff, line);
	command = strtok(line, SPLIT_STRING);
	while (command != NULL)
	{
		commandCount++;
		command = strtok(NULL, SPLIT_STRING);
	}
	commandTokens = _calloc((commandCount + 2), sizeof(char *));
	if (commandTokens == NULL)
	{
		free(buff);
		return (NULL);
	}
	command = strtok(buff, SPLIT_STRING);
	commandCount = 0;
	while (command)
	{
		commandTokens[commandCount] = _calloc(_strlen(command) + 2,
				sizeof(char *));
		if (commandTokens[commandCount] == NULL)
		{
			for (i = 0; commandTokens[commandCount]; i++)
				free(commandTokens[i]);
			free(commandTokens), free(buff);
			return (NULL);
		}
		_strcpy(commandTokens[commandCount], command);
		commandCount++;
		command = strtok(NULL, SPLIT_STRING);
	}
	commandTokens[commandCount] = NULL;
	free(buff);
	return (commandTokens);
}
