#include "shell.h"

/**
 * _strncmp - Compare amount (n) of characters of two strings
 * @s1: A string
 * @s2: A string
 * @n: Amount of charcter to compare.
 *
 * Return: 1 If the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
		return (-1);

	for (; n > 0; s1++, s2++, n--)
	{
		if (*s1 != *s2)
			return (1);
		
		if (*s2 == '\0')
			return (1);
	}

	return (0);
}

/**
 * _strcpy - Copy source string to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to destination string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;

	return (dest);
}


/**
 * _strcat - COncatenate two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destiantion string
 */
char *_strcat(char *dest, const char *src)
{
	char *s = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return (s);
}


/**
 * _strchr - Locate the character in string
 * @s: String to search in
 * @c: Character to search for
 *
 * Return: Pointer to the first occurrence of 'c' in 's',
 * or NULL if not found
 *
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;

	return ((*s == c) ? s : NULL);
}

/**
 * _strncmp - Compare amount (n) of characters of two stings.
 * @s1: A string
 * @s2: A string
 * @n: Amount of characters to compare
 *
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (1);

		if (s2[i] == '\0')
			return (0);
	}

	return (0);
}


