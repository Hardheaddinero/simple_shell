#include "shell.h"
/**
 * signal_to_handel - Handle ^C
 * @sig: Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
		exit(EXIT_SUCCESS);
	}
}
/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
