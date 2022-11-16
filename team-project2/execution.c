#include "shell.h"

/**
 * execution - function that executes the commands entered by users
 * @cp: vector array of pointers to command
 * @cmd:commands
 * Return: 0
 */
void execution(char *cmd, char **cp)
{
	pid_t child_pid;
	int stat;
	char **envi = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd);
	if (child_pid == 0)
	{
		execve(cmd, cp, envi);
		perror(cmd);
		free(cmd);
		free_buffers(cp);
		exit(98);
	}
	else
		wait(&stat);
}
