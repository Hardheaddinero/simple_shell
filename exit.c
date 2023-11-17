#include "shell.h"

/**
 * exit_bul - Exit Status Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv: Program Name
 * @c: Execute Count
 * Return: Void (Exit Status)
 */
void exit_bul(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
	puts("Error: Invalid exit status");
}

