#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 */
typedef struct info_s
{
	char **argv;
	char *path;
	list_t *env;
	char **environ;
	int err_num;
	int status;
} info_t;

/**
 * struct list_str - singly linked list
 * @num: number field
 * @str: string
 * @next: points to the next node
 */
typedef struct list_str
{
	int num;
	char *str;
	struct list_str *next;
} list_t;

int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
char *build_file_path(const char *directory, const char *command);
char *search_in_single_directory(const char *directory, const char *command);
char *search_in_path(const char *path, const char *command);
char *check_command_in_directories(const char *path, const char *command);
char *get_location(char *command);
void execmd(char **argv);

void interactive_shell(void);
void handle_command(char *command);
int main(void);

#endif
