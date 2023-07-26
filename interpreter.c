#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - returns number of elements
 * @env: environmental variable
 * @argc: handle arguments
 * @av: argument vector for code
 *
 * Return: command line interpreter
 */
int main(int argc, char **av, char *env)
{
	pid_t  pid;
	pid_t ppid = getpid();
	int i, exec = 0;
	size_t n = 0;
	char *buf = "#cisfun$ ";
	char *lineptr, *token;
	char *argv[] = {"", NULL};
	/** free, programs exits after execve, handle return type of execve **/
	while (1)
	{
		write(STDOUT_FILENO, buf, 9);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			exit(EXIT_FAILURE);
		}
		token = strtok(lineptr, "\n");
		argv[0] = token;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror(av[0]);
		}
		else
		{
			wait(&pid);
		}
	}
	return (0);
}

