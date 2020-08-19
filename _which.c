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
	/*char error_info[100];*/
	char *dirCopied;
	char *pathHelper;

	pathHelper = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (pathHelper == NULL)
	{
		return (NULL);
	}
	pathHelper = _strcpy(pathHelper, pathVariable);

	dirObtained = strtok(pathHelper, ":");
	while (dirObtained != NULL)
	{
		dirCopied = malloc(sizeof(char) * MAX_BUFFER_SIZE);

		if (dirCopied == NULL)
		{
			return (NULL);
		}
		dirCopied = _strcpy(dirCopied, dirObtained);
		_strcat(dirCopied, "/");
		_strcat(dirCopied, commandSearched);

		if (stat(dirCopied, &buf) != 0)
		{
			/*free(dirCopied);*/
			dirCopied = NULL;
		}
		else
			break;
		dirObtained = strtok(NULL, ":");
	}

	free(pathHelper);
	return (dirCopied ? dirCopied : commandSearched);
}
