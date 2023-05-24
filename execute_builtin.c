#include "shell.h"

/**
 * execute_builtin_cd - Execute the "cd" command.
 * @args: Arr of arguments passed to the command.
 * Return: 0 on success, -1 on error.
 */
int execute_builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument to \"cd\"\n");
		return (-1);
	}

	if (chdir(args[1]) != 0)
	{
		perror("cd");
		return (-1);
	}

	return (0);
}

/**
 * execute_builtin_exit - Executes the "exit" command.
 * @args: Arr of arg passed to the command.
 * Return: -1 to indicate exit status.
 */
int execute_builtin_exit(char **args)
{
	(void)args;
	return (-1);
}

/**
 * execute_builtin_help - Executes the "help" command.
 * @args: Arr of arg passed to the command.
 * Return: 0 on success.
 */
int execute_builtin_help(char **args)
{
	printf("Help page:\n");
	printf("  cd <directory>- Change the current directory\n");
	printf("  exit		- Exit the shell\n");
	printf("  help		- Display help information\n");

	(void)args;
	return (0);
}

/**
 * is_builtin - Checks if a command is a built-in command.
 * @command: The command to check.
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */
int is_builtin(char *command)
{
	if	(strcmp(command, "cd") == 0 ||
		strcmp(command, "exit") == 0 ||
		strcmp(command, "help") == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * execute_builtin - Executes a built-in command.
 * @args: Arr of arg passed to the command.
 * Return: 0 on success, -1 on error or if the command is not a built-in command.
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		return (execute_builtin_cd(args));
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		return (execute_builtin_exit(args));
	}
	else if (strcmp(args[0], "help") == 0)
	{
	return (execute_builtin_help(args));
	}

	fprintf(stderr, "%s: command not found\n", args[0]);
	return (-1);
}
