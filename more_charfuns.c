#include "shell.h"

/**
 * _itoa - Convert Inteher to Char
 * @n: Int to convert
 *
 * Return: Pointer to the converted string, or NULL on failure
 */
char *_itoa(unsigned int n)
{
	char *result, *ptr;

	result = malloc(12);

	if (!result)
		return (NULL);

	ptr = result;
	do {
		*ptr++ = (n % 10) + '0';
	} while (n /= 10);

	*ptr = '\0';

	/* Reverse the string */
	reverse(result, ptr - result);

	return (result);
}

/**
 * reverse - Reverse string
 * @str: String to Reverse
 * @len: Length of String
 *
 * Return: Void(Reverse string)
 */

void reverse(char *str, int len)
{
	int i;
	char tmp;

	for (i = 0; i < len / 2; i++)
	{
		tmp = st[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}


