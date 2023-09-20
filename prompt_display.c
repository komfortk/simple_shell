#include "shell.h"

/**
 * display_prompt - displays the prompt
 * @prompt: the shell prompt
 */
void display_prompt(const char *prompt)
{
	write(STDOUT_FILENO, prompt, strlen(prompt));
}
