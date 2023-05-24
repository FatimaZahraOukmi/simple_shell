#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int status = 1;

	while (status)
	{
		char buffer[1024];
		char *args[64];
		int i = 0;

		printf("%s", PROMPT);
		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		line = remove_newline(line);
		args[0] = strtok(line, " ");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}

		if (is_builtin(args[0]))
			status = execute_builtin(args);
		else
			status = execute_external(args);
	}

	free(line);
	return (0);
}
