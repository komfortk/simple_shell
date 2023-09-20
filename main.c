#include "shell.h"

int count_tokens(const char *input, const char *delim);
char *input_read();
char **cp_tokens(const char *input, const char *delim,
		int token_num);
char **tokenize_input(char *input);
void handle_command(char *command);
void interactive_shell(void);

/**
 * main - entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	ssize_t getline_re;
	char *lineptr = NULL;
	char *prompt = "($) ";
	size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));

		getline_re = getline(&lineptr, &n, stdin);

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
	return (0);
}
