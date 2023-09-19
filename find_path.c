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


/**
 * build - Build command
 * @token: Executable command
 * @value: Directory containing command
 *
 * Return: Parsed full path of command or NULL case failed
 */
char *build(char *token, char *value)
{
	size_t value_len = _strlen(value);
	size_t token_len = _strlen(token);

	/* Calculate the total length needed for cmd */
	size_t len = value_len + token_len + 2;

	char *cmd = malloc(len);

	if (cmd == NULL)
		return (NULL);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}


/**
 * _getenv - Gets the value of an environment variable by name
 * @name: Environment variable name
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(char *name)
{
	size_t len = strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			char *value = _strdup(environ[i] + len + 1);

			return (value);
		}
	}

	return (NULL);

}
