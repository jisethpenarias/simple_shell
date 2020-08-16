#include "simple_shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_dirPath (char *var)
{
	char *token;
	char *varFounded;
	int i;
	char *helper;

	helper = malloc(sizeof(char)* 1024);
	if(!helper)
		return;// imprimir un error

	i = 0;
	varFounded = _getenv(var);
	if(!varFounded)
	{
		return; //imprimir un error
	}
	token = strtok(varFounded, ":");
	printf("%s\n",token);
	while (token != NULL) {
		i++;
		token = strtok(NULL, ":");
		if (token)
		     printf("%s\n", token);
	}
	//NO OLVIDAR EL FREEEEEEE
}

void main ()
{
	print_dirPath("PATH");
	return;
}
