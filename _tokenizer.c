#include "shell.h"

/**
 * count_tokens - function that counts tokens in a string
 * @input: input string to count tokens from
 * @delim: number of delimiters
 *
 * Return: number of tokens found in string
 */
int count_tokens(const char *input, const char *delim)
{
	int token_num = 0;
	char *token;
	char *input_cpy = strdup(input);

	if (input_cpy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
	}

	token = strtok(input_cpy, delim);

	while (token != NULL)
	{
		token_num++;
		token = strtok(NULL, delim);
	}

	free(input_cpy);
	return (token_num);
}

/**
 * cp_tokens - function to allocate and copy tokens into an array
 * @input: input string
 * @delim: numer of delimiters
 * @token_num: number of tokens to copy
 *
 * Return: an array of dynamically allocated strings containing tokens
 */
char **cp_tokens(const char *input, const char *delim, int token_num)
{
	char *token;
	char **argv = (char **)malloc(sizeof(char *) * (token_num + 1));
	int i;
	char *input_cpy;

	if (argv == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
	}

	input_cpy = strdup(input);

	if (input_cpy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
	}

	token = strtok(input_cpy, delim);

	for (i = 0; i < token_num; i++)
	{
		argv[i] = strdup(token);

		if (argv[i] == NULL)
		{
			perror("tsh: memory allocation error");
			exit(-1);
		}

		token = strtok(NULL, delim);
	}

	argv[token_num] = NULL;
	free(input_cpy);

	return (argv);
}


/**
 * tokenize_input - tokenizes a string into an array of tokens
 * @input: input string to tokenize
 *
 * Return: an array of dynamically allocated strings
 */
char **tokenize_input(char *input)
{
	const char *delim = " \n";
	int num_tokens = count_tokens(input, delim);
	char **argv = cp_tokens(input, delim, num_tokens);

	return (argv);
}
