#include "simple_shell.h"

/**
 * _strcmp - checks if 2 strings are of equal value
 * @s1: destination string
 * @s2: source string to be copied
 *
 * Return: difference of first characters that are of diff value
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

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

/**
 * _strcpy - copy char array
 * @dest : dest
 * @src : source
 *
 * Return: desc
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = *(src + i);
	return (dest);
}

/**
 *_strcat - concatenates two strings
 *@dest: destination string
 *@src: source string
 *
 *Return: pointer to concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, s;

	i = 0;
	s = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[s] != '\0')
	{
		dest[i] = src[s];
		i++;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _calloc - Allocates memory for an array.
 * @nmemb: Size of space to allocate.
 * @size: Size of bytes of the type of variable.
 *
 * Return: Pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pointer;
	unsigned int i;
	unsigned int tamano;

	tamano = nmemb * size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < tamano; i++)
	{
		pointer[i] = 0;
	}
	return (pointer);
}
