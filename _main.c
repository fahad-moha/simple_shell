#include "_shell.h"

/**
 * main - The entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: The exit status of the program.
 */
int main(int argc, char *argv[])
{
	char *replacedCommand;
	char **args;
	char command[MAX_COMMAND_LENGTH];
	int commandLength;

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
	if (argc == 2)
	{
		executeCommandsFromFile(argv[1]);
	}
	else
	{
		runInteractiveShell();
	}
	return (0);
}

