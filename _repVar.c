#include "_shell.h"

/**
 * replaceVariables - Replaces variables in a command
 * with their respective values.
 * @command: The command containing variables.
 * Return: The command with variables replaced by their values.
 */
char *replaceVariables(char *command)
{
	char *result;
	int i, resultIndex, commandLength;
	char *value;
	char *variable;
	int j;

	result = malloc(MAX_COMMAND_LENGTH * sizeof(char));
	if (!result)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	resultIndex = 0;
	commandLength = strlen(command);
	i = 0;
	while (i < commandLength)
	{
		if (command[i] == '$')
		{
			if (command[i + 1] == '?')
			{
				value = getVariableValue("$?");
				if (value != NULL)
				{
					strcpy(result + resultIndex, value);
					resultIndex += strlen(value);
				}
				i += 2;
			}
			else if (command[i + 1] == '$')
			{
				value = getVariableValue("$$");
				if (value != NULL)
				{
					strcpy(result + resultIndex, value);
					resultIndex += strlen(value);
				}
				i += 2;
			}
			else if (command[i + 1] == '{')
			{
				j = i + 2;
				while (j < commandLength && command[j] != '}')
				{
					j++;
				}
				if (j < commandLength)
				{
					variable = malloc((j - i - 2 + 1) * sizeof(char));
					if (!variable)
					{
						fprintf(stderr, "Allocation error\n");
						exit(EXIT_FAILURE);
					}
					strncpy(variable, command + i + 2, j - i - 2);
					variable[j - i - 2] = '\0';
					value = getVariableValue(variable);
					if (value != NULL)
					{
						strcpy(result + resultIndex, value);
						resultIndex += strlen(value);
					}
					free(variable);
					i = j + 1;
				}
				else
				{
					result[resultIndex] = command[i];
					resultIndex++;
					i++;
				}
			}
			else
			{
				result[resultIndex] = command[i];
				resultIndex++;
				i++;
			}
		}
		else
		{
			result[resultIndex] = command[i];
			resultIndex++;
			i++;
		}
	}
	result[resultIndex] = '\0';
	return (result);
}

