#include "shell.h"

/**
 * command_exists - Execute simple shell command (Fork, Execute, Wait)
 *
 * @cmd: Parsed commnd
 * @input: User input
 * @c: Shell execution time case of command not found
 * @argv: program Name
 *
 * Return: 1 case command Null -1 wrong command 0 command executed
 */

int command_exists(char **cmd, char *input, int c, char **argv)
{
	pid_t pid;

	if (*cmd == NULL)
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
			is_path_cmd(cmd);
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
		int status;

		wait(&status);
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}

	return (0);
}
