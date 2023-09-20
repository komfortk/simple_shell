#include "shell.h"

/**
 * handle_command - function that handles commands
 * @command: input
 */
void handle_command(char *command)
{
	pid_t pid;
	size_t len;

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
		char **argv;

		argv = malloc(2 * sizeof(char *));
		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, NULL);

		perror("execve");
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
