#include "shell.h"

/**
 * execmd - Executes a command with execve, searching for the full command
 *          path in PATH.
 *
 * Description: This function takes the command as an argument and searches
 *              for its full path in the directories specified by the PATH
 *              environment variable. If found, the command is executed
 *              using execve.
 *
 * @argv: An array of strings containing the command and its arguments.
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];

		actual_command = get_location(command);

		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}
