#include "shell.h"

/**
 *checker- Check if its a built in function
 *@cmd: user input
 *@buf: line driven from the getline function
 *Return: 1 if cmd excuted and 0 if cmd is not executed
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}

/**
* prompt_user - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
*
* Return: no return
*/

void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 *handle_signal- it keeps track in interactive mode
 *@n: the signal number
 *Return: nothing
 */

void handle_signal(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

/**
* tokenizer - create tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/

char **tokenizer(char *line)
{
	char *buf = NULL, *bufpt = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufpt = buf;

	while (*bufpt)
	{
		if (_strchr(delim, *bufpt) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufpt) == NULL && flag == 1)
			flag = 0;
		bufpt++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
