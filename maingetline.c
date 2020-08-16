#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
	        _getlline(&buffer, &len, STDIN_FILENO);
		printf("%s", buffer);
	}
	return (0);
}
