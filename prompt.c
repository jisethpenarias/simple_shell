#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t prompt()
{
        char *buffer;
        size_t size = 1024;
        ssize_t rd, wr;

        write(STDOUT_FILENO,"$ ", 2);

        buffer = malloc(sizeof(char) * size);
        if (buffer == NULL)
		return (-1);

        rd = read(STDIN_FILENO, buffer, size);
        wr = write(STDOUT_FILENO, buffer, rd);

	if (rd == -1 || rd != wr)
	{
		free(buffer);
		return (-1);
	}
        free(buffer);
        return (rd);
}
int main()
{
        prompt();
        return(0);
}
