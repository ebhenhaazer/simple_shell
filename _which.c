#include "main.h"
#include <stdbool.h>

#include <stdbool.h>

/**
 * is_valid_path - Check if the filename represents a valid path.
 *
 * @filename: The filename to check.
 *
 * Return: true if the filename is a relative or absolute path, false otherwise.
 */
bool is_valid_path(const char *filename)
{
    return ((filename[0] == '.' && (filename[1] == '/' || filename[1] == '.')) || filename[0] == '/');
}


/**
 * filepath_creator - short description
 *
 * Description: long description
 *
 * @file_path: argument_1 description
 * @array_of_tokens: argument_2 description
 * @filename: file name string
 * @token_index: index to copy
 *
 * Return: void
 */
void filepath_creator(char **file_path, char **array_of_tokens,
		char *filename, int token_index)
{
	allocate_memory_for_char(file_path,
			(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, array_of_tokens[token_index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - description that is short
 *
 * Description: description that is long
 *
 * @filename: description for argument_1 
 *
 * Return:  description returned
 */
char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **array_of_tokens;
	int token_index, file_path_exist;

	delimiter = ":";
	path_var = getenv("PATH");
	if (path_var != NULL)
	{
		array_of_tokens = create_array_from_input(path_var, delimiter);
		if (array_of_tokens != NULL)
		{
			for (token_index = 0; array_of_tokens[token_index]; token_index++)
			{
				filepath_creator(&file_path, array_of_tokens, filename, token_index);
				file_path_exist = stat(file_path, &sb);
				if (file_path_exist == 0)
				{
					free_path_tokens(&path_var, array_of_tokens);
					return (file_path);
				}
				free(file_path);
			}
			free_path_tokens(&path_var, array_of_tokens);
		}
		else
			free(path_var);
	}
	file_path_exist = stat(filename, &sb);
	if (file_path_exist == 0 && is_valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
