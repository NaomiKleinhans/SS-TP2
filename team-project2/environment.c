#include "shell.h"

/**
* print_env - function to print the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
	int i = 0;
	char **envi = environ;

	while (envi[i])
	{
		write(STDOUT_FILENO, (const void *)envi[i], _strlen(envi[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
