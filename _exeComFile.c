#include "_shell.h"

/**
 * executeCommandsFromFile - Executes commands read from a file.
 * @filename: The name of the file containing commands.
 */
void executeCommandsFromFile(char *filename)
{
	FILE *file;
	char command[MAX_COMMAND_LENGTH];
	char *replacedCommand;
	char **args;
	int commandLength;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, MAX_COMMAND_LENGTH, file))
	{
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
	fclose(file);
}

