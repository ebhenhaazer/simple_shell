#include "main.h"

/**
 * _exit_builtin - The exit command builtin in shell
 *
 * @tokens: Array of command tokens
 *
 * Return: 1 if success, 0 if failure
 */
int _exit_builtin(char **tokens)
{
	char *exit_argument = tokens[1];

	if (exit_argument != NULL)
	{
		int exit_code = atoi(exit_argument);

 		exit(exit_code);
	}
	else
	{
		return (DEFAULT_EXIT_CODE);
	}
}
