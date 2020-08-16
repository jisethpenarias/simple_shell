#include <stdio.h>
#include <unistd.h>

/**
 * getppid - will return process id of parent function
 *
 * Return: void.
 */

int main(void)
{
	pid_t my_pidf;

	my_pidf = getppid();
	printf("%u\n", my_pidf);
	return (0);
}

