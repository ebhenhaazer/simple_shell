#include "main.h"

/**
 * display_prompt - Display a prompt symbol if the program is
 * running interactively.
 *
 * Description:
 * This function checks if the standard input is associated with a terminal
 * to determine if the program is running interactively. If it is, the function
 * displays the prompt symbol "$ " to indicate that the program is ready to
 * receive user input.
 *
 * Return:
 * This function doesn't have a return value (void).
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 9);
}
