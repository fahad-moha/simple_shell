#include "shell.h"

/**
 * _putchar - writes the characteer c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _strncpy -  copy a  string
 * @dest: Destination string
 * @src: Source string
 * @n: Number of characters to copy
 *
 * Return: Pointer to the destination string
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}


/**
 * _puts - Print a string followed by a newline
 * @str: Pointer  to a string
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}



/**
 * _strlen - Length of a string
 * @s: Pointer to a string
 *
 * Return: Length of the string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);

}


/**
 * _atoi - Convert a string to an integer
 * @s: String
 *
 * Return: Integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;/* Toggle sign if '-' is encountered */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + (s[i] - '0');
		}
		else if (res != 0)
		{
			break; /**
				 * Stop if a non-digit character
				 * is encountered after passing digits
				 */
		}
		i++;
	}

	return (sign * res);
}
