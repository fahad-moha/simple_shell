#include "shell.h"

/**
 * print_number - Print a unsigned integer using _putchar
 * @n: Unsigned integer
 *
 * Return: void
 */
void print_number(unsigned int n)
{
	if (n >= 10)
		print_number(n / 10);

	_putchar ((n % 10) + '0');
}

/**
 * print_number_in - Print an integer using _putchar
 * @n: Integer
 *
 */
void print_number_in(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n >= 10)
	{
		print_number_in(n / 10);
	}

	_putchhar(n % 10 + '0');
}
