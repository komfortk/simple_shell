#include "shell.h"

/**
 * interactive_shell - runs the shell in interactive mode, reading commands
 *                     from the user and executing them
 */
void interactive_shell(void)
{
	char *prompt = "($) ";
	char *lineptr = NULL;
	size_t n = 0;

	while (1)
	{
		ssize_t getline_re = getline(&lineptr, &n, stdin);

		write(STDOUT_FILENO, prompt, strlen(prompt));

		if (getline_re == -1)
		{
			write(STDOUT_FILENO, "\nExit shell....\n", strlen("\nExit shell....\n"));
			break;
		}

		if (strcmp(lineptr, "exit\n") == 0)
		{
			write(STDOUT_FILENO, "Exit shell....\n", strlen("Exit shell....\n"));
			break;
		}

		handle_command(lineptr);
	}

	free(lineptr);
}


/**
 * non_interactive_shell - Runs the shell in non-interactive mode, reading
 *                        commands from a file and executing them.
 *
 * @command_file: The path to the file containing commands.
 */
void non_interactive_shell(const char *command_file)
{
	FILE *file = fopen(command_file, "r");
	char *lineptr = NULL;
	size_t n = 0;

	if (!file)
	{
		perror("Error opening command file");
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, file) != -1)
	{
		size_t len = strlen(lineptr);

		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';

		handle_command(lineptr);
	}

	free(lineptr);
	fclose(file);
}
