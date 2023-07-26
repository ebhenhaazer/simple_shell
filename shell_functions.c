#include "shell_functions.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_env.h"

/**
 * print_environment - Function to print the environment variables.
 * @env_var: The environment variable array.
 */
void print_environment(char **env_var)
{
while (*env_var != NULL)
{
int i = 0;
while ((*env_var)[i] != '\0')
{
write(STDOUT_FILENO, &(*env_var)[i], 1);
i++;
}
write(STDOUT_FILENO, "\n", 1);
env_var++;
}
}

/**
 * is_equal - Function to check if two strings are equal.
 * @str1: First string.
 * @str2: Second string.
 * Return: 1 if strings are equal, 0 otherwise.
 */
int is_equal(char *str1, char *str2)
{
while (*str1 && (*str1 == *str2))
{
str1++;
str2++;
}
return (*str1 == *str2);
}

/**
 * execute_command - Function to execute a command using execve.
 * @command: The command to be executed.
 * @arguments: Array of arguments for the command.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char *arguments[])
{
pid_t pid = fork();
if (pid < 0)
{
perror("Fork failed");
return (-1);
}
else if (pid == 0)
{
if (execve(command, arguments, NULL) == -1)
{
perror("Execve failed");
_exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
return (0);
}

