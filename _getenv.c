#include "simple_shell.h"

/**
 * _getenv - Gets an environment variable.
 *
 * Return: Pointer to an environment variable or NULL if not found.
 */

char *_getenv()
{
	char *value;
	int i = 0;
	char *env;
	char *envValue;
	char var[5] = "PATH";

	envValue = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (envValue == NULL)
		return (NULL);

	env = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (env == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		_strcpy(env, environ[i]);
		value = strtok(env, "=");
		if (_strcmp(value, var) == 0)
		{
			_strcpy(envValue, strtok(NULL, "="));
			/*free(env);*/
			return (envValue);
		}
		i++;
	}

	return (NULL);
}