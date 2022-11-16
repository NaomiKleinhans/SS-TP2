#include "shell.h"

/**
* test_path - Test if path is valid
* @path: tokenized path
* @command: command entered by users
*
* Return: path appended with command on success
* NULL on failure
*/
char *test_path(char **path, char *cmd)
{
	int i = 0;
	char *result;

	while (path[i])
	{
		result = append_path(path[i], cmd);
		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	return (NULL);
}

/**
* append_path - adds path to command
* @path: path of command
* @command: user entered command
*
* Return: buffer containing command with path on success
* NULL on failure
*/
char *append_path(char *path, char *cmd)
{
	char *buf;
	size_t i = 0, j = 0;

	if (cmd == 0)
		cmd = "";
	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));

	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (cmd[j])
	{
		buf[i + j] = cmd[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

/**
* handle_builtin - handles all builtin functions by execution
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/

int handle_builtin(char **cmd, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
	{
		exit_cmd(cmd, line);

		return (1);
	}
	return (0);
}

/**
* exit_cmd - function that handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/

void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
