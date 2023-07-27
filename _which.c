#include "main.h"

/**
* is_valid_path - Check if the filename is a valid path.
*
* Description: This function checks if the given filename is a valid path.
*              It examines the beginning characters of the filename to see
*              if it starts with "../", "./", or "/".
*
* @filename: The filename string to check.
*
* Return: 1 if the filename is a valid path, 0 otherwise.
*/
#include <string.h>

int is_valid_path(char *filename)
{
size_t length = strlen(filename);
size_t prefix_length;
char *prefixes[] = { "../", "./", "/" };
size_t num_prefixes = sizeof(prefixes) / sizeof(prefixes[0]);
size_t i;

for (i = 0; i < num_prefixes; i++)
{
prefix_length = strlen(prefixes[i]);
if (length >= prefix_length && strncmp(filename, prefixes[i], prefix_length) == 0)
return 1;
}

return 0;
}


/**
* filepath_creator - Create a file path based on a token and a filename.
*
* Description: This function creates a new file path by combining a token
*              from the PATH environment variable and the provided filename.
*
* @file_path: Pointer to store the newly created file path.
* @array_of_tokens: Token array obtained by splitting the PATH environment variable.
* @filename: The filename string to append to the token.
* @token_index: Index of the token in the array to use for file path creation.
*
* Return: None.
*/
void filepath_creator(char **file_path, char **array_of_tokens, char *filename, int token_index)
{
malloc_str(file_path,
(strlen(array_of_tokens[token_index]) + strlen(filename) + 2),
"_which Error: malloc failed for file_path");
strcpy(*file_path, array_of_tokens[token_index]);
strcat(*file_path, "/");
strcat(*file_path, filename);
strcat(*file_path, "\0");
}

/**
* _which - short description
*
* Description: long description
*
* @filename: argument_1 description
*
* Return: return description
*/
#include <string.h>
#include <unistd.h>

/**
* _which - Find the absolute path of an executable file.
*
* Description:
* This function searches for the absolute path of the executable file specified
* by the filename in the PATH environment variable. It checks each token in the
* PATH, concatenates it with the filename, and verifies if the file exists using
* the stat() function.
*
* @filename: The filename of the executable file.
*
* Return:
* The absolute path of the executable file if found, or NULL if not found.
*/
char *_which(char *filename)
{
struct stat sb;
char *path_var, *delimiter, *file_path;
char **array_of_tokens;
int token_index, file_path_exist;

delimiter = ":";
path_var = get_env("PATH");
if (path_var != NULL)
{
array_of_tokens = make_token_array(path_var, delimiter);
if (array_of_tokens != NULL)
{
for (token_index = 0; array_of_tokens[token_index]; token_index++)
{
filepath_creator(&file_path, array_of_tokens, filename, token_index);
file_path_exist = stat(file_path, &sb);
if (file_path_exist == 0)
{
free_exec_path(&path_var, array_of_tokens);
return file_path;
}
free(file_path);
}
free_which(&path_var, array_of_tokens);
}
else
free(path_var);
}
else
return NULL; /* Early return if PATH is not set */

/* Check the provided filename as a relative or absolute path */
file_path_exist = stat(filename, &sb);
if (file_path_exist == 0 && is_valid_path(filename))
return strdup(filename);

return NULL;
}


