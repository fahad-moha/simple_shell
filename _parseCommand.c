#include "_shell.h"

/**
 * parseCommand - Parses a command into an array of arguments.
 * @command: The command to be parsed.
 * Return: An array of arguments.
 */
char **parseCommand(char *command)
{
	char **args;
	int argIndex, argLength, i, commandLength;

	args = malloc((MAX_ARGUMENTS + 1) * sizeof(char *));
	if (!args)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	argIndex = 0;
	argLength = 0;
	commandLength = strlen(command);
	for (i = 0; i <= commandLength; i++)
	{
		if (command[i] == ' ' || command[i] == '\0')
		{
			if (argLength > 0)
			{
				args[argIndex] = malloc((argLength + 1) * sizeof(char));
				if (!args[argIndex])
				{
					fprintf(stderr, "Allocation error\n");
					exit(EXIT_FAILURE);
				}
				strncpy(args[argIndex], command + i - argLength, argLength);
				args[argIndex][argLength] = '\0';
				argIndex++;
				argLength = 0;
			}
		}
		else
		{
			argLength++;
		}
	}
	args[argIndex] = NULL;
	return (args);
}

