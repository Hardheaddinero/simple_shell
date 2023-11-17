#include "shell.h"

/**
 * comments - remove comments from the command line
 * @line: command line argument
 *
 * Return: command without comments
 */

char *comments(char *line)
{
	if (line == NULL)
		return (NULL);

	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}

	return (line);
}
