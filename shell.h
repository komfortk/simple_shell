#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUF_SIZE 1024;

/**
 * struct info_s - Information about the shell command
 * @argv: Arguments of the command
 * @path: string path for current command
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from linked list env
 * @err_num: Error number or code
 * @status: Status of the command execution
 * @readfd: fd from which to read line input
 */
typedef struct info_s
{
	char **argv;
	char *path;
	char **environ;
	int err_num;
	int status;

	int readfd;
} ShellInfo;

char *dup_chars(char *pathstr, int start, int stop);
char *find_path(ShellInfo *shell_info, char *pathstr, char *cmd);
char *build_file_path(const char *directory, const char *command);
char *search_in_single_directory(const char *directory, const char *command);
char *search_in_path(const char *path, const char *command);
char *check_command_in_directories(const char *path, const char *command);
char *get_location(char *command);
void execmd(char **argv);

void interactive_shell(void);
void non_interactive(const char *command_file);
void handle_command(char *command);
void display_prompt(const char *prompt);
int count_tokens(const char *input, const char *delim);
char **cp_tokens(const char *input, const char *delim, int token_num);
char **tokenize_input(char *input);
char *input_read();
int main(void);

#endif
