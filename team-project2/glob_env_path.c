#include "shell.h"

/**
* find_path - function that finds the path from the global enviroment
* Return: NULL if path is not found or path if path is found.
*/

char *find_path(void)
{
	int i;
	char **envi = environ, *path = NULL;

	while (*envi)
	{
		if (_strncmp(*envi, "PATH=", 5) == 0)
		{
			path = *envi;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		envi++;
	}
	return (NULL);
}
