#include "_shell.h"

/**
 * executeCommand - Executes a command with the given arguments.
 * @args: The array of command arguments.
 */
void executeCommand(char **args)
{
	if (args[0] == NULL)
	{
		return;
	}
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (strcmp(args[0], "set") == 0)
	{
		if (args[1] != NULL)
		{
			setVariable(args[1]);
		}
		else
		{
			fprintf(stderr, "Missing argument for set command\n");
		}
		return;
	}
	printf("Executing command: %s\n", args[0]);
}


