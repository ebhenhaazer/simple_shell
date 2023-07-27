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
	ssize_t num_chars_read = 0;
	const size_t init_bufsize = 1024;
	char buffer[init_bufsize];

	prompt();
	/** Read a line from stdin using fgets. */
	if (fgets(buffer, init_bufsize, stdin) == NULL)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	/** Calculate the number of characters read. */
	num_chars_read = strlen(buffer);

	/** Check if the buffer needs to be resized */
	if (*size < num_chars_read)
	{
		*size = num_chars_read;
		*input = (char *)realloc(*input, (*size + 1) * sizeof(char));
		if (*input == NULL)
		{
			fprintf(stderr, "Memory reallocation failed.\n");
			exit(status);
		}
	}
	/** Copy the content from the buffer to the input buffer. */
	strncpy(*input, buffer, num_chars_read);

	return (num_chars_read);
}

