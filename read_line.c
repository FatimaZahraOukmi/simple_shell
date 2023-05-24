#include "shell.h"

/**
 * read_line - Reads a line of input.
 * Return: The input line as a dynamically allocated str.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	characters_read = getline(&line, &bufsize, stdin);
	if (characters_read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	return (line);
}
