#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

/**
 * execute_external - Executes an external command.
 * @args: Array of args passed to the command.
 * Return: 0 on success, -1 on error.
 */
int execute_external(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{

		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
		if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		else
		{
			do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				return (-1);
			}
		}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

	return (0);
}
