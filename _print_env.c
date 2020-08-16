#include "simple_shell.h"

int _print_env(void)
{
        unsigned int i;

        i = 0;
        while (environ[i] != NULL)
        {
                printf("input main[%d]:%s\n", i, environ[i]);
                i++;
        }
        return (0);
}
