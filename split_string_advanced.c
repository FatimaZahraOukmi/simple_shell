#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100


/*
 * Splits a string into multiple substrings based on a delimiter.
 * Returns an array of substrings.
 *
 * Parameters:
 *   str: The string to be split.
 *   delim: The delimiter used to split the string.
 *
 * Returns:
 *   An array of substrings.
 */
char **split_string(char *str, const char *delim);

/*
 * The main function is the entry point of the program.
 * It reads a str input from user, splits it into tokens using a delimiter,
 * and prints each token.
 *
 * Returns:
 *   0 on successful execution.
 */
int main(void)
{
	char input[100];

	printf("Enter a string: ");

	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	char **tokens = split_string(input, " ");
	int i = 0;

	while (tokens[i] != NULL)
	{
		printf("Token %d: %s\n", i, tokens[i]);
		free(tokens[i]);
		i++;
	}
	free(tokens);

	return (0);
}

/*
 * Splits a str into multiple substrings based on a delimiter.
 * Returns an array of dynamically allocated str.
 *
 * Parameters:
 *   str: The str to be split.
 *   delim: The delimiter used to split the str.
 *
 * Returns:
 *   An array of dynamically allocated str, representing the tokens.
 *   The last element of the array is NULL.
 */
char **split_string(char *str, const char *delim)
{
	char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
	int token_count = 0;

	char *token = strtok(str, delim);

	while (token != NULL)
	{
		tokens[token_count] = (char *)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(tokens[token_count], token);
		token_count++;
		token = strtok(NULL, delim);
	}
	tokens[token_count] = NULL;

	return (tokens);
}
