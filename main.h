#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

struct bltn_cmd
{
    char *n;
    int (*function)(char **tokens);
};

int digits(size_t num);
int set_env(const char *name, const char *value, int overwrite);
void reverse_string(char *s);
int fork_process(char *command, char **tokens);
char *search_path(char *filename);
void display_prompt(void);
char *get_env(const char *name);
int print_environment(void);
void free_path_tokens(char **path_tokens, char **tokens);
int unset_env(const char *name);
int exit_builtin(char **tokens);
int copy_tokens(char **dest, char **src);
int env_length(void);
void free_tokens(char **tokens, char *input);
int is_builtin_command(char **tokens);
int env_variable_exists(const char *name);
int handle_command_not_found(char **argv, char **tokens, size_t command_num);
char *allocate_memory_for_char(char **string, size_t size, char *error_message);
ssize_t get_input_line(char **input, size_t *size, int status);
int handle_builtin_command(char **tokens);
char **allocate_memory_for_array(char **array, size_t size, char *error_message);
int unset_env(const char *name);
int exit_builtin(char **tokens);
char **create_array_from_input(char *input, char *delimiter);
char *integer_to_string(size_t num);
int set_env(const char *name, const char *value, int overwrite);

#endif

