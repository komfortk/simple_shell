#include "shell.h"

/**
 * handle_command - function that handles commands
 * @command: input
 */
void handle_command(char *command)
{
	pid_t pid;
	size_t len;
	/*Remove the newline character at the end of the command*/
	len = strlen(command);
	if (len > 0 && command[len - 1] == '\n')
		command[len - 1] = '\0';

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		char **argv; /*Declare argv as a pointer to a pointer to char*/

		argv = malloc(2 * sizeof(char *)); /*Allocate memory for argv*/
		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		argv[0] = command;
		argv[1] = NULL; /*Null-terminate the argv array*/

		execve(command, argv, NULL);

		perror("execve");
		free(argv); /*Free the allocated memory*/
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
