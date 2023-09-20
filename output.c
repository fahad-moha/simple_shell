#include "shell.h"

/**
 * _prerror - Print custom error
 * @argv: program Name
 * @c: error
 * count
 * @cmd: command
 * Return: void
 */

void _prerror(char **argv, int c char **cmd)
{
	char *slip = _itoa(c);

	DISPLAY(argv[0]);
	DISPLAY(": ");
	DISPLAY(slip);
	DISPLAY(": ");
	DISPLAY(cmd[0]);
	DISPLAY(": Illegal number: ");
	DISPLAY(cmd[1]);
	DISPLAY("\n");
	free(slip);
}

