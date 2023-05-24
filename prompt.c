#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* command = NULL;
	size_t bufsize = 0;
	printf("$ ");
	fflush(stdout); /* Flush stdout to ensure prompt is displayed*/

	ssize_t line_size = getline(&command, &bufsize, stdin);
	if (line_size == -1)
	{
		printf("Error reading input.\n");
		free(command);
		return 1;
	}

	printf("Command: %s", command);
	free(command);
	return (0);
}
