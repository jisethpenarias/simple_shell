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
	/**
	 * if (dirObtained == NULL)
	 * printf("NOT FOUND\n");
	 */

	return (NULL);
}
