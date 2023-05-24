#ifndef _shell_h_
#define _shell_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "shell $ "

/**
 * struct builtin_d - Defines the builtins functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */
typedef struct builtin_d
{
        char *built;
        void (*f)(char *);
} builtin_t;

extern char **environ;

char **token_interface(char *, const char *, int);
int count_token(char *, const char *);
char **tokenize(int, char *, const char *);
void create_child(char **, char *, int, char **);
void parse_line(char *, size_t, int, char **);
char *path_finder(char *);
int str_len(char *);
int find_path(char *);
char **tokenize_path(int, char *);
char *search_directories(char **, char *);
char *build_path(char *, char *);
void double_free(char **);
void single_free(int, ...);

/* Builtin functions */
int built_in(char **, char *);
void (*check_built_ins(char *))(char *);
void exit_b(char *);
void env_b(char *);
void cd_b(char *);

/* Library functions */
int _strcmp(char *, char *);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);

/* Helper functions */
void error_printing(char *, int, char *);
void exec_error(char *, int, char *);

#endif
