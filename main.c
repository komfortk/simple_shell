#include "shell.h"

int count_tokens(const char *input, const char *delim);
char *input_read();
char **cp_tokens(const char *input, const char *delim,
		int token_num);
char **tokenize_input(char *input);
void handle_command(char *command);

/**
 * main - entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *input;
	char **tokens;
	char *prompt = "($) ";
	int i;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		input = input_read();

		if (input == NULL)
			continue;

		tokens = tokenize_input(input);

		if (tokens == NULL)
		{
			free(input);
			continue;
		}
		handle_command(input);

		free(input);
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);
	}

	return (0);
}
