#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _get_input_line - Read a line of input from the user.
 *
 * @input: Pointer to the input buffer.
 * @size: Pointer to the size of the input buffer.
 * @status: Exit status.
 *
 * Return: Number of characters read on success, -1 on failure.
 */
ssize_t _get_input_line(char **input, size_t *size, int status)
{
	ssize_t num_chars_read;

	display_prompt();
	/** Read a line from stdin using fgets. */
	num_chars_read = getline(input, size, stdin);
	if (num_chars_read == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}

	return (num_chars_read);
}

