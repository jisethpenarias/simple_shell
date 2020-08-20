#include "simple_shell.h"

/**
 * _getenv - Gets an environment variable.
 * @variable: PATH variable.
 * @env: Environment variable.
 *
 * Return: Pointer to an environment variable or NULL if not found.
 */

char *_getenv(char *variable, char **env)
{
	char *value1 = NULL, *value2 = NULL;
	int i = 0;
	char *enValue1 = NULL, *enValue2 = NULL;

	enValue1 = _strdup(variable);

	while (env[i] && env)
	{
		enValue2 = NULL;
		value2 = NULL;
		enValue2 = _strdup(env[i]);
		value1 = strtok(enValue2, "=");
		value2 = _strdup(strtok(NULL, "="));
		if (_strcmp(enValue1, value1) == 0)
		{
			break;
		}
		free(enValue2);
		free(value2);
		i++;
	}
	free(enValue2);
	enValue2 = NULL;
	free(enValue1);

	return (value2);
}
