#include "shell.c"

/**
 * parse_cmd - Parse a line of input into tokens
 * @input: User input to parse
 *
 * Return: Array of parsed tokens or NULL on failure
 */

char **parse_cmd(char *input)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;
	int buffsize = BUFSIZE;
	char **new_tokens;

	if (input == NULL)
		return (NULL);

	token = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);

	}

	while ((tken = _strtok((i == 0) ? input : NULL, "\n")))
	{
		token[i++] = token;

		if (i >= buffsize)
		{
			buffsize += BUFSIZE;
			new_tokens = realloc(token, sizeof(char *) * buffsize);
			if (!new_token)
			{
				perror("hsh");
				free(tokens);
				return (NULL);
			}
			tokens = new_tokens;
		}
	}

	tokens[i] = NULL; /* NUll-terminate the array */

	return (tokens);
}

