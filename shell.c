#include "shell.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>

void parse_line(char *line, size_t size, int command_counter, char **av);
void create_child(char **param_array, char *line, int count, char **av);
char **tokenize(char *line, const char *delim, int *token_count);
int count_token(char *line, const char *delim);

int main(__attribute__((unused)) int ac, char **av)
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter, av);
	} while (1);

	return (0);
}

void parse_line(char *line, size_t size, int command_counter, char **av)
{
	int i;
	ssize_t read_len;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	write(STDOUT_FILENO, PROMPT, str_len(PROMPT));
	read_len = getline (&line, &size, stdin);
	if (read_len != -1)
	{
		param_array = tokenize(line, delim, &token_count);
		if (param_array == NULL || param_array[0] == NULL)
		{
			if (param_array != NULL)
				free(param_array);
			free(line);
			return;
		}
		i = built_in(param_array, line);
		if (i == -1)
			create_child(param_array, line, command_counter, av);
		for (i = 0; param_array[i] != NULL; i++)
			free(param_array[i]);
		free(param_array);
		free(line);
	}
	else
		exit_b(line);
}

void create_child(char **param_array, char *line, int count, char **av)
{
	pid_t id;
	int status;
	int i;
	int check;
	struct stat buf;
	char *tmp_command;
	char *command;

	id = fork();
	if (id == 0)
	{
		tmp_command = param_array[0];
		command = path_finder(param_array[0]);
		if (command == NULL)
		{
		 /* Looking for file in current directory */
			check = stat(tmp_command, &buf);
			if (check == -1)
			{
				error_printing(av[0], count, tmp_command);
				print_str(": not found", 0);
				free(line);
				for (i = 1; param_array[i]; i++)
					free(param_array[i]);
				free(param_array);
				exit(100);
			}
			/* File exists in current working directory or has full path */
			command = tmp_command;
		}
		param_array[0] = command;
		if (param_array[0] != NULL)
		{
			if (execve(param_array[0], param_array, environ) == -1)
				exec_error(av[0], count, tmp_command);
		}
	}
	else
		wait(&status);
}

char **tokenize(char *line, const char *delim, int *token_count)
{
	char **param_array;
	char *token;
	int i;

	*token_count = count_token(line, delim);
	if (*token_count == -1)
		return (NULL);

	token = strtok(line, delim);
	char **param_array = malloc(sizeof(char*) * (token_count + 1));
	for (i = 0; token != NULL; i++)
	{
		param_array [i] = _strdup(token);
		if (param_array[i] == NULL)
		{
			double_free(param_array);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	param_array[i] = NULL;

	return (param_array);
}

int count_token(char *line, const char *delim)
{
	int count = 0;
	int in_token = 0;
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (strchr(delim, line[i]) != NULL)
		{
			if (in_token)
			{
				in_token = 0;
			}
		}
		else
		{
			if (!in_token)
			{
				in_token = 1;
				count++;
			}
		}
	}

	return (count);
}
