#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: void
 */
int main(int ac, char *av[])
{
	int i = 0;
	char *str = av[0];
	struct stat sb;

	while (str[i])
	{
		i++;
	}
	if (ac != 2)
	{
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	if (stat(av[1], &sb) == -1)
	{
		write(STDERR_FILENO, av[0], i);
		write(STDERR_FILENO, ": NOT FOUND\n", 12);
		exit(EXIT_FAILURE);
	}
	write(STDOUT_FILENO, av[0], i);
	write(STDOUT_FILENO, ": FOUND\n", 8);
	return (0);
}

