#include "shell.h"

/**
* _strcmp - function that compares two strings
* @s1: compared to s2;
* @s2: compared to s1;
*
* Return: returns difference between strings
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, result;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	result = (*(s1 + i) - *(s2 + i));

	return (result);
}

/**
* _strlen - function that returns the length of a string
* @s: string passed
*
* Return: returns length of string passed
*/
int _strlen(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

/**
* _strncmp - function that compares two strings up to n bytes
* @s1: compared to s2
* @s2: compared to s1
* @n: number of bytes
*
* Return: difference between s1 and s2
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
* _strdup - function that dupicates string
* @st: to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *st)
{
	char *ptr;
	int i, leng;

	if (st == NULL)
		return (NULL);

	leng = _strlen(st);

	ptr = malloc(sizeof(char) * (leng + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *st != '\0'; st++, i++)
		ptr[i] = st[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* _strchr - function that locates a character in a string
* @s: string to be checked
* @c: character to be located
*
* Return: returns pointer to first occurence of character
* or NULL if character not found
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
