#include "_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

char *variables[MAX_ARGUMENTS];
int numVariables = 0;

/**
 * displayPrompt - Displays the shell prompt.
 */
void displayPrompt(void)
{
	printf("$ ");
}

/**
 * getVariableValue - Retrieves the value of a given variable.
 * @variable: The name of the variable.
 * Return: NULL.
 */
char *getVariableValue(char *variable)
{
	char *pid;
	int i;

	if (strcmp(variable, "$?") == 0)
	{
		return ("0");
	}
	else if (strcmp(variable, "$$") == 0)
	{
		pid = malloc(10 * sizeof(char));
		if (!pid)
		{
			fprintf(stderr, "Allocation error\n");
			exit(EXIT_FAILURE);
		}
		snprintf(pid, 10, "%d", getpid());
		return (pid);
	}
	else
	{
		for (i = 0; i < numVariables; i++)
		{
			if (strcmp(variable, variables[i]) == 0)
			{
				return (getenv(variables[i]));
			}
		}
	}
	return (NULL);
}

/**
 * setVariable - Sets the value of a variable.
 * @variable: The name of the variable.
 */
void setVariable(char *variable)
{
	if (numVariables < MAX_ARGUMENTS)
	{
		variables[numVariables] = malloc((strlen(variable) + 1) * sizeof(char));
		if (!variables[numVariables])
		{
			fprintf(stderr, "Allocation error\n");
			exit(EXIT_FAILURE);
		}
		strcpy(variables[numVariables], variable);
		numVariables++;
	}
	else
	{
		fprintf(stderr, "Maximum number of variables reached\n");
	}
}

