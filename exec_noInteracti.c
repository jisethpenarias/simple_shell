#include "simple_shell.h"

/**
 * exec_noInteracti - Receive the commands sent from main.
 * @av: Pointer to strings with arguments.
 * Return: void.
 **/

int exec_noInteracti(char **av)
{
	char info_error[100];

	sprintf(info_error, "hsh: %s: not found\n", *av);
	write(2, info_error, _strlen(info_error));
	return (0);
}
