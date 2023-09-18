#include "shell.h"


/**
 * is_path_cmd - Search in $PATH for Executable command
 * @cmd: Paresed input (updated if found in $PATH)
 *
 * Return: 0 on success, 1 otherwise
 */

int is_path_cmd(char **cmd)
{
	char *path = _getenv("PATH");
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");

	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value  = _strtok(NULL, ":")
	}
	free(path);

	return (1);
}
