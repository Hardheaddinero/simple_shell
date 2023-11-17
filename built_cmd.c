#include "shell.h"
/**
 * change_dir - Change Directory
 * @cmd: Parsed Command
 * @er: Status of Last Command Executed
 * Return: 0 Success 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **cmd, __attribute__((unused)) int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		puts("Error: Directory not found");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - Display Environment Variable
 * @cmd: Parsed Command
 * @er: Status of Last Command Executed
 * Return: Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		puts(environ[i]);
	}
	return (0);
}

/**
 * display_help - Displaying Help For Builtin
 * @cmd: Parsed Command
 * @er: Status Of Last Command Executed
 * Return: 0 Success -1 Fail
 */
int display_help(char **cmd, __attribute__((unused)) int er)
{
	int fd, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		puts("Error: File not found");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		if (rd < 0)
		{
			puts("Error: Failed to read file");
			close(fd);
			return (-1);
		}
		puts(&c);
	}
	close(fd);
	return (0);
}

/**
 * echo_bul - Execute Echo Cases
 * @st: Status Of Last Command Executed
 * @cmd: Parsed Command
 * Return: Always 0 Or Execute Normal Echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		puts("");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		puts("");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		puts(path);
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}
