#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "> "
#define CMD_SIZE 100

void prompt() {
	printf(PROMPT);
}

char* read_command() {
	char *cmd = malloc(CMD_SIZE);
	fgets(cmd, CMD_SIZE, stdin);
	return cmd;
}

int exit_cmd(char **args) {
	free(args[0]);
	exit(EXIT_SUCCESS);     
}

void execute(char *cmd) {
	errno = 0;
	execvp(cmd, NULL);
	if (errno != 0) {
		printf("Command not found.\n");
	}
}

int main() {
	char *cmd;  

	while(1) {
		prompt();
		cmd = read_command();
		cmd[strcspn(cmd, "\n")] = 0;

		// Check for exit
		if(strcmp(cmd, "exit") == 0) {
			exit_cmd(NULL);
		}
		
		execute(cmd);
		free(cmd);
	}
}
