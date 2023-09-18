#include "shell.h"

/**
 * _putchar - writes the characteer c to stdout
 * @c: The character to print
 *
 * ReturnL On success 1.
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
		ddest[i] = '\0';
		i++;
	}

	return (dest);
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

