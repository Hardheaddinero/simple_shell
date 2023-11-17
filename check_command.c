#include "shell.h"
/**
 * check_cmd - Execute Simple Shell Command (Fork, Wait, Execute)
 *
 * @cmd: Parsed Command
 * @input: User Input
 * @c: Shell Execution Time Case of Command Not Found
 * @argv: Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (cmd == NULL || *cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (-1);
}
