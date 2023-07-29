#include "main.h"

/**
 * _fork_process - Create a child process and execute a command.
 *
 * Description: This function creates a child process using
 * the fork system call and attempts to execute the specified
 * command in the child process using the execve system call.
 *
 * @command: A pointer to a string representing the command to be executed.
 * @tokens: A pointer to an array of strings representing the arguments
 *             to be passed to the command.
 *
 * Return: On success, returns the exit status of the child process if running
 *         interactively; otherwise, returns 0. On failure, returns -1.
 */
int _fork_process(char *command, char **tokens)
{
	pid_t child_pid;
	int child_status, execve_err;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("_fork() Error: Unable to create child process");
		return (-1);
	}

	if (child_pid == 0)
	{
		/* Child process */
		execve_err = execve(command, tokens, __environ);
		if (execve_err == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		/* Parent process */
		wait(&child_status);
		free(command);
		if (WIFEXITED(child_status))
			child_status = WEXITSTATUS(child_status);

		/* Check if running interactively and return the status */
		if (!isatty(STDIN_FILENO))
			return (child_status);
	}

	/* Return 0 to indicate successful execution if running interactively */
	return (0);
}
