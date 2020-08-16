#include "simple_shell.h"

/**
 *_strlen - calculate the length of a string
 *
 *@s:pointer intput
 *
 * Return: c
 */

int _strlen(char *s)
{
	int c;

	c = 0;

	while (s[c] != 0)
	{
		c++;
	}
	return (c);
}
