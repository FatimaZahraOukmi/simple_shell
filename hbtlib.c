#include "shell.h"

/**
 * _strcmp - compares two str
 * @s1: First str
 * @s2: Second str
 * Return: 0 if str match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (str_len(s1) != str_len(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * _strdup - create a copy of a str
 * @src: Contains the original str
 * Return: Gives back the copy of str
 */
char *_strdup(char *src)
{
	int i;
	int len;
	char *dest;

	len = str_len(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * print_str - Prints a str character by character.
 * @str: String to be printed. If the string is NULL it will print (null)
 * @new_line: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */
void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * _write_char - Writes a char to stdout
 * @c: Char that will be written to stdout
 * Return: when success how many char were written.
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
