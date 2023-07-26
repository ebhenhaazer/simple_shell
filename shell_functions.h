#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

void print_environment(char **env_var);
int is_equal(char *str1, char *str2);
int execute_command(char *command, char *arguments[]);

#endif /* SHELL_FUNCTIONS_H */

