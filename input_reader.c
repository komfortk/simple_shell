#include "shell.h"

/**
 * input_read - Reads a line of input from the user
 *
 * Return: dynamically allocated string containing the user's input
 */
char *input_read()
{
	ssize_t getline_re;
	char *lineptr = NULL;
	size_t n = 0;

	getline_re = getline(&lineptr, &n, stdin);

	if (getline_re == -1)
	{
		write(STDOUT_FILENO, "Exit shell....\n", 15);
		exit(-1);
	}

	return (lineptr);
}
