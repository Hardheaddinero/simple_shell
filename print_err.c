#include "shell.h"

/**
 *  _prerror - Print Custom Error
 * @argv: Program Name
 * @c: Error Count
 * @cmd: Command
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er;

	if (cmd == NULL || cmd[1] == NULL)
	{
		PRINTER("Error: invalid command\n");
		return;
	}

	er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input: User Input
 * @counter: Simple Shell Count Loop
 * @argv: Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	if (er == NULL)
	{
		PRINTER("Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
