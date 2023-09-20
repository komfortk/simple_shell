#include "shell.h"

void interactive_shell(void);

/**
 * exit_shell - function that exits shell
 */
void exit_shell(void)
{
	char *exit_msg = "Exiting shell\n";

	write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
	exit(0);
}
