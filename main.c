#include "main.h"

/**
* main - Entry point for the shell program
*
* Description: This function serves as the main loop for the shell program.
*              It reads user input, tokenizes it, and executes commands.
*
* @argc: The number of command-line arguments (unused)
* @argv: Array of command-line arguments (unused)
* @envp: Array of environment variables (unused)
*
* Return: Always returns 0
*/
int main(__attribute__((unused)) int argc,
__attribute__((unused)) char **argv,
__attribute__((unused)) char **envp)
{
	int status = 0;
	char *user_input, *delimiter, *command_path;
	size_t input_buffer_size, command_count;
	char **tokenized_commands;
	
	signal(SIGINT, hand_sig); /* Set up signal handler for SIGINT (Ctrl+C) */
	
	user_input = NULL;
	input_buffer_size = command_count = 0;
	delimiter = " \n";
	
	do
	{
		command_count++;
		_get_input_line(&user_input, &input_buffer_size, status); /* Read user input */
		tokenized_commands = create_array_from_input(user_input, delimiter); /* Tokenize the input string */
		
		if (*tokenized_commands) /* Check if the first token is not NULL (non-empty input) */
		{
			if (is_builtin_command(tokenized_commands)) /* Check if the command is a built-in command */
			{
				if (handle_builtin_command(tokenized_commands) == DEFAULT_EXIT_CODE) /* Execute built-in command */
				{
					free_tokens(tokenized_commands, user_input);
					exit(status);
				}
			}
			else
			{
				command_path = _which(tokenized_commands[0]); /* Check if the command exists in the system */
				if (command_path != NULL)
					status = _fork_process(command_path, tokenized_commands); /* Fork a child process to execute the command */
				else
					status = handle_command_not_found(argv, tokenized_commands, command_count); /* Command not found */
			}
		}
		
		free_tokens(tokenized_commands, user_input); /* Free allocated memory and reset variables */
		user_input = NULL;
	}
	while (1);
	return (0);
}
