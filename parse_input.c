#include "shell.h"

char **parse_input(char *line)
{
	int token_count = count_token(line, " ");
	char **tokens = NULL;
	char *token = NULL;
	int i;

	tokens = malloc((token_count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, " ");
	for (i = 0; i < token_count; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			double_free(tokens);
			return (NULL);
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}
