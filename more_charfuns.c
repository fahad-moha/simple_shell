#include "shell.h"

/**
 * _itoa - Convert Inteher to Char
 * @n: Int to convert
 *
 * Return: Pointer to the converted string, or NULL on failure
 */
char *_itoa(unsigned int n)
{
	int len;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);

	if (!s)
		return (NULL);

	s[len] = '\0';/* NUll - terminate the string */

	while (len-- > 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
	}

	return (s);
}

