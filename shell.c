#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell_functions.h"
#include "shell_env.h"


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * handle_exit_command - Function handles "exit" command and terminate shell
 * @arguments: Array of arguments for the command
 */
void handle_exit_command(char *arguments[]);
/**
 * handle_env_command - Function handles "env" command, print the env variables
 * @env_var: The environment variable array
 */
void handle_env_command(char **env_var);
/**
 * handle_external_command - Function to handle external commands using execve.
 * @arguments: Array of arguments for the command
 */
void handle_external_command(char *arguments[]);

/**
 * main - The main function for the shell.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
char *command = NULL;
char *saveptr;
ssize_t input_length;
char *arguments[MAX_ARGUMENTS];
char *token;
int arg_count = 0;

/* Get the environment variables*/
char **env_var = environ;

while (1)
{
write(STDOUT_FILENO, "#cisfun$ ", 9);

/* Allocate memory for the command */
command = (char *)malloc(MAX_COMMAND_LENGTH);
if (command == NULL)
{
perror("Memory allocation failed");
_exit(EXIT_FAILURE);
}

input_length = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
if (input_length == -1)
{
perror("Read error");
free(command);
_exit(EXIT_FAILURE);
}

/* Check for EOF (Ctrl+D) */
if (input_length == 0)
{
write(STDOUT_FILENO, "\n", 1);
free(command);
_exit(EXIT_SUCCESS);
}

command[input_length - 1] = '\0';

/* Reset arg_count for each new command */
arg_count = 0;

token = strtok_r(command, " ", &saveptr);
while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
{
arguments[arg_count] = token;
arg_count++;
token = strtok_r(NULL, " ", &saveptr);
}
arguments[arg_count] = NULL;

/* Check if the command is "exit" and terminate the shell if it is */
if (arg_count > 0 && is_equal(arguments[0], "exit"))
{
handle_exit_command(arguments);
}
/* Check if the command is "env" and print the environment if it is */
else if (arg_count > 0 && is_equal(arguments[0], "env"))
{
handle_env_command(env_var);
}
/* Check if the command exists using access */
else if (access(arguments[0], X_OK) == 0)
{
handle_external_command(arguments);
}
/* Command not found */
else
{
write(STDERR_FILENO, "No such file or directory\n", 18);
}

/* Free the allocated memory for the command */
free(command);
}

return (0);
}

/**
 * handle_exit_command - handles "exit" command and terminate the shell.
 * @arguments: Array for cmd
 */
void handle_exit_command(char *arguments[])
{
if (arguments[1] != NULL)
{
int status = atoi(arguments[1]);
_exit(status);
}
else
{
_exit(EXIT_SUCCESS);
}
}


/**
 * handle_env_command - Function handles "env" cmd. prints env variables
 * @env_var: The environment variable array
 */
void handle_env_command(char **env_var)
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
 * handle_external_command - Function to handle external commands using execve.
 * @arguments: Array of arguments for the command.
 */
void handle_external_command(char *arguments[])
{
if (execute_command(arguments[0], arguments) != 0)
{
_exit(EXIT_FAILURE);
}
}

