#include "shell.h"

/**
 * remove_newline - Removes the trailing newline char from a str.
 * @str: The str to remove the newline char from.
 * Return: The modified str with the newline char removed.
 */
char *remove_newline(char *str)
{
	size_t length = strlen(str);
	
	if (length > 0 && str[length - 1] == '\n')
	str[length - 1] = '\0';

	return str;
}
