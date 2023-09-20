#include "shell.h"

/**
 * _prints_environment - print the current environment variables to stdout
 */
void _prints_environment(void)
{
	char **env = environ;
	int _stdout_fd = STDOUT_FILENO;

	while (*env)
	{
		write(_stdout_fd, *env, strlen(*env));
		write(_stdout_fd, "\n", 1);
		env++;
	}
}

/**
 * print_file_environment - print the current environment
 *                             variables to a file
 * @filename: name of the file to write the environment variables to
 * Return: 0 on success, -1 on failure.
 */
int print_file_environment(const char *filename)
{
	char **env = environ;
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("open");
		return (-1);
	}

	while (*env)
	{
		if (write(fd, *env, strlen(*env)) == -1)
		{
			perror("write");
			close(fd);
			return (-1);
		}

		if (write(fd, "\n", 1) == -1)
		{
			perror("write");
			close(fd);
			return (-1);
		}
		env++;
	}

	close(fd);
	return (0);
}
