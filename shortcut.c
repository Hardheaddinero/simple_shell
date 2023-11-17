#include "shell.h"

/**
 * shortcut_cmd - Signal Handler for Ctrl+C
 * @num: Reset handler to catch SIGINT next time.
 * Return: void
 */
void shortcut_cmd(int num)
{
	if (num != SIGINT)
		return;

	if (signal(SIGINT, shortcut_cmd) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

	if (write(STDOUT_FILENO, "\n$ ", 3) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	if (fflush(stdout) == EOF)
	{
		perror("fflush");
		exit(EXIT_FAILURE);
	}
}
