#include "shell.h"

/**
 * _itoa - Convert Inteher to Char
 * @n: Int to convert
 *
 * Return: Pointer to the converted string, or NULL on failure
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len  = intlen(n);
	s = malloc(len + 1);

	if (!s)
		return (NULL);

	*s = '\0'; /* Null-terminate the string first */

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		i++;
	}
	s[i] = (n % 10) + '0';

	/* Reverse the string */
	reverse(s, len);
	s[i + 1] = '\0';
	return (s);

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
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}


/**
 * intlen - Determine the length of an integer
 * @num: Given integer
 *
 * Return: Length of the integer
 */
int intlen(int num)
{
	int len;


	if (num == 0)
		return (1);

	len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;

	}

	return (len);
}

