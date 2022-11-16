#include "shell.h"
/**
* main - Entry point carrying out the read, execute then print of output loop
* @ac: argument count
* @av: argument vector
* @envi: environment vector
* Return: 0
*/
int main(int ac, char **av, char *envi[])
{
	char *buf = NULL, *pathcmd = NULL, *path = NULL;
	size_t buf_size = 0;
	ssize_t line_size = 0;
	char **cmd = NULL, **paths = NULL;
	(void)envi, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffers(cmd);
		free_buffers(paths);
		free(pathcmd);
		prompt_user();
		line_size = getline(&buf, &buf_size, stdin);
		if (line_size < 0)
			break;
		info.ln_count++;
		if (buf[line_size - 1] == '\n')
			buf[line_size - 1] = '\0';
		cmd = tokenizer(buf);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (checker(cmd, buf))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcmd = test_path(paths, cmd[0]);
		if (!pathcmd)
			perror(av[0]);
		else
			execution(pathcmd, cmd);
	}
	if (line_size < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(buf);
	return (0);
}
