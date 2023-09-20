#include "shell.h"

/**
 * build_file_path - builds the full file path by concatenating a directory
 *                   path and a command
 * @directory: directory path
 * @command: the command
 * Return: dynamically allocated string containing the full file path
 */
char *build_file_path(const char *directory, const char *command)
{
	size_t dir_len = strlen(directory);
	size_t cmd_len = strlen(command);
	char *file_path = malloc(dir_len + cmd_len + 2);

	if (file_path)
	{
		strcpy(file_path, directory);
		strcat(file_path, "/");
		strcat(file_path, command);
	}

	return (file_path);
}

/**
 * search_in_single_directory - searches for a command in a single directory
 * @directory: directory to search in
 * @command: command to search for
 * Return: the full path to the command if found, NULL otherwise
 */
char *search_in_single_directory(const char *directory, const char *command)
{
	char *file_path = build_file_path(directory, command);
	struct stat buffer;

	if (stat(file_path, &buffer) == 0)
	{
		return (file_path);
	}

	free(file_path);

	return (NULL);
}

/**
 * search_in_path - searches for a command in the specified PATH
 * @path: the PATH environment variable
 * @command: command to search for
 * Return: the full path to the command if found, NULL otherwise
 */
char *search_in_path(const char *path, const char *command)
{
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char *result = NULL;

	while (path_token != NULL)
	{
		result = search_in_single_directory(path_token, command);

		if (result)
		{
			free(path_copy);

			return (result);
		}

		path_token = strtok(NULL, ":");
	}

	free(path_copy);

	return (NULL);
}

/**
 * check_command_in_directories - checks if a command exists in directories
 *                                specified by PATH or in the current directory
 * @path: the PATH environment variable
 * @command: the command to check
 *
 * Return: the full path to the command if found, NULL otherwise
 */
char *check_command_in_directories(const char *path, const char *command)
{
	char *location = search_in_path(path, command);

	if (location)
	{
		return (location);
	}

	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}

	return (NULL);
}

/**
 * get_location - retrieves the full path to the executable command
 * @command: command to find
 * Return: the full path to the command if found, NULL otherwise
 */
char *get_location(char *command)
{
	char *path = getenv("PATH");

	if (path)
	{
		char *result = check_command_in_directories(path, command);

		return (result);
	}

	return (NULL);
}
