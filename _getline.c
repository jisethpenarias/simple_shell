#include "simple_shell.h"

int _getline(char **lineptr, size_t *size, int stream)
{
	int rd = 0;

	rd = read(stream, *lineptr, *size);
	if (rd == 0)
		return (-1);
	else if (rd < 0)
	{
		free(*lineptr);
		return (-1);
		/*crear un exit.*/
	}
	(*lineptr)[rd] = '\0';
	return (rd);
}
