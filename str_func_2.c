#include "simple_shell.h"

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 *
 * Return: diference
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[j]);
	}
}

/**
 *_memset - function that fills memory with a constant byte.
 *@s: buffer
 *@b: constant byte
 *@n: size
 *
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 *_calloc - function that allocates memory for an array,
 * @nmemb: size array
 * @size: the size of the memory to print
 * Return:arr
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	arr = malloc(size * nmemb + 1);
	if (!arr)
	{
		return (NULL);
	}
	_memset(arr,  0, (size * nmemb));
	return (arr);
}
