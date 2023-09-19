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
	DISPLAY(argv[0]);
	DISPLAY(": ");
	DISPLAY(_itoa(counter));
	DISPLAY(": ");
	DISPLAY(input);
	DISPLAY(": not found\n");
}
