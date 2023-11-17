#include "shell.h"

/**
 * _memcpy - Copies bytes from source to destination
 * @dest: Destination pointer
 * @src: Source pointer
 * @n: Number of bytes to copy
 * Return: Pointer to the destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - Fills an array with a constant byte
 * @a: Pointer to the array
 * @el: Constant byte to fill the array with
 * @len: Length of the array
 * Return: Pointer to the array
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * free_all - Frees an array of char pointer and a char pointer
 * @cmd: Array pointer
 * @line: Char pointer
 * Return: void
 */
void free_all(char **cmd, char *line)
{
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
}
