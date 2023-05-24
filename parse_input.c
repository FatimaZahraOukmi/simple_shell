#include "shell.h"

/**
 * parse_input - Tokenizes input line into separate arg.
 * @line: input line to be parsed.
 * Return: An array of str (arguments) terminated by a NULL pointer.
 */
char **parse_input(char *line)
{
	const char *delimiters = " \t\n";
	char *token;
	char **args;
	int token_count = 0;

	if (line == NULL)
		return (NULL);

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiters);
	}

	args = malloc((token_count + 1) * sizeof(char *));
	if (args == NULL)
		return (NULL);

	token = strtok(line, delimiters);
	for (int i = 0; i < token_count; i++)
	{
		args[i] = token;
		token = strtok(NULL, delimiters);
	}
	args[token_count] = NULL;

	return (args);
}
