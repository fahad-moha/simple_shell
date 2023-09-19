#include "shell.h"

/**
 * prompt - Display shell prompt
 */
void prompt(void)
{
	DISPLAY("$ ");
}


/**
 * print_error - Display error message for a command not found
 * @input: User input
 * @counter: Simple shell loop count
 * @argv: Program name
 */
void print_error(char *input, int counter, char **argv)
{
	char *slip;


	DISPLAY(argv[0]);
	DISPLAY(": ");
	slip = _itoa(counter);
	DISPLAY(slip);
	free(slip);
	DISPLAY(": ");
	DISPLAY(input);
	DISPLAY(": not found\n");
}
