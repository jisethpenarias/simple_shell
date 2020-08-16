#include "simple_shell.h"

char *_getenv(char *var)
{
	char *value;
	int i = 0;
	char *env;
	char *envValue;

	envValue = malloc(sizeof(char)* 1024);
	if (envValue == NULL)
		return (NULL);

	env = malloc(sizeof(char) * 1024);
	if (env == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		strcpy(env, environ[i]);
		value = strtok(env, "=");
		if (strcmp(value,var) == 0)
		{
			strcpy(envValue, strtok(NULL, "="));
			return (envValue);
		}
		i++;
	}
	return (NULL);
}
