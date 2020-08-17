#include "simple_shell.h"

/**
 * _which - Search a command of the PATH.
 * @pathVariable: PATH variable.
 * @commandSearched: Command to search.
 *
 * Return: Return 0.
 */

char *_which(char *pathVariable, char *commandSearched)
{
	struct stat buf;
	char *dirObtained;
	char error_info[100];
	char *dirCopied;

	dirObtained = strtok(pathVariable, ":");
	while (dirObtained != NULL)
	{
		dirCopied = strdup(dirObtained);
		strcat(dirCopied, "/");
		strcat(dirCopied, commandSearched);
		if (stat(dirCopied, &buf) == 0)
		{
			return (dirCopied);
		}
		dirObtained = strtok(NULL, ":");
	}

	if (dirObtained == NULL)
	{
		sprintf(error_info, "hsh: %s: not found\n",
			commandSearched);
		write(2, error_info, _strlen(error_info));
	}

	free(dirCopied);
	return (NULL);
}
