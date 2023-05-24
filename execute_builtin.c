#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * execute_builtin - Executes a built-in command.
 * @args: Arr of arg passed to the command.
 * Return: 0 on success, -1 on error or if the command is not a built-in.
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "Expected argument to \"cd\"\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("chdir");
			}
		}
		return (0);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (-1);
	}

	if (strcmp(args[0], "help") == 0)
	{
		printf("This is a simple shell program.\n");
		printf("Supported built-in commands:\n");
		printf("cd <directory>: Change current directory\n");
		printf("exit: Exit the shell\n");
		printf("help: Display help information\n");
		return (0);
	}

	/* Command is not a built-in */
	return (-1);
}
