#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		printf("$ ");
		line = read_line();
		line = remove_newline(line);
		args = parse_input(line);

		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}

		if (is_builtin(args[0]))
		{
			status = execute_builtin(args);
		}
		else
		{
			status = execute_external(args);
		}

		free(line);
		free(args);

		if (status == -1)
		{
			printf("An error occurred.\n");
		}
	}

	return (0);
}
