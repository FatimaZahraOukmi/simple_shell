#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *args[64];
	int i, status;

	while (1)
	{
	printf("#cisfun$ ");
	fgets(buffer, BUFFER_SIZE, stdin);

	buffer[strcspn(buffer, "\n")] = '\0';

	char *token = strtok(buffer, " ");
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}
