#include "simple_shell.h"

char * _strdup ( char * str)
{
	char * dup ;
	int i;

	si (str == NULL )
		return ( NULL );

	i = 0 ;
	mientras (str [i])
		i ++;

	dup = malloc ( tamaño de ( carácter ) * (i + 1 ));
	si ( dup == NULL )
		return ( NULL );

	i = 0 ;
	mientras (str [i])
	{
		dup [i] = str [i];
		i ++;
	}

	dup [i] = ' \ 0 ' ;

	retorno ( dup );
}
