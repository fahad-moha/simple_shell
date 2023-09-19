#include "_shell.h"

/**
 * runInteractiveShell - Runs the interactive shell.
 */
void runInteractiveShell(void)
{
	int commandLength;
	char *replacedCommand;
	char **args;
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		displayPrompt();
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		commandLength = strlen(command);
		if (command[commandLength - 1] == '\n')
		{
			command[commandLength - 1] = '\0';
		}
		if (command[0] == '#')
		{
			continue;
		}
		replacedCommand = replaceVariables(command);
		args = parseCommand(replacedCommand);
		executeCommand(args);
		free(replacedCommand);
		free(args);
	}
}

