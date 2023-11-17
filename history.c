#include "shell.h"

/**
 * history - Fill File By User Input
 * @input: User Input
 * Return: -1 Fail 0 Success
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0600);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}

	if (input)
	{
		while (input[len])
			len++;

		w = write(fd, input, len);
		if (w == -1)
		{
			perror("write");
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (0);
}

