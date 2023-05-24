#include "shell.h"

/**
 * _strlen - Computes the length of a str.
 * @str: The str to compute the length of.
 *
 * Return: The length of the str.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
	    len++;

	return (len);
}

/**
 * _strcmp - Compares two str.
 * @s1: The first str to compare.
 * @s2: The second str to compare.
 *
 * Return: 0 if the str are equal, a negative value if s1 is less than s2,
 *         or a positive value if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strdup - Duplicates a str.
 * @str: The str to duplicate.
 *
 * Return: On success, a pointer to the duplicated str.
 *         On failure, NULL.
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len, i;

	if (str == NULL)
		return (NULL);


	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[i] = '\0';

	return (dup);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
