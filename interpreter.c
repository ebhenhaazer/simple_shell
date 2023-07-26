#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Custom shell program
 * @argc: Number of arguments
 * @av: Argument vector for the program
 *
 * Return: Always 0
 */
int main(int argc, char **av)
{
	pid_t pid;
	size_t n = 0;
	char *buf = "#cisfun$ ";
	char *lineptr, *token;
	char *argv[] = {"", NULL};

	(void)argc; /* Suppress unused parameter warning */
	(void)av;   /* Suppress unused parameter warning */

	/* free, programs exit after execve, handle return type of execve */
	while (1)
	{
		write(STDOUT_FILENO, buf, 9);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			if (feof(stdin)) /* Check if EOF (ctrl-D) was encountered */
			{
				putchar('\n'); /* Print a newline after ctrl-D */
				exit(EXIT_SUCCESS); /* Exit the program gracefully */
			}
			exit(EXIT_FAILURE);
		}
		token = strtok(lineptr, "\n");
		argv[0] = token;

		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror(argv[0]);
		}
		else
		{
			wait(&pid);
		}
	}
	return (0);
}

