#include "simple_shell.h"

/**
 * _signal_handle - Function that controls the Ctrl + C (^ C)
 * @singint: The signal that enters.
 *
 * Return: Void.
 */

void _signal_handle(int singint)
{
	if (singint)
		write(STDIN_FILENO, "\n$ ", 3);
}
