#include "main.h"

/**
* allocate_memory_for_char - Allocate memory for a character array.
*
* Description: This function dynamically allocates memory for a character
*              array of given size.
*
* @string: Pointer to a pointer to char that will be updated to point
* to the newly allocated memory.
* @size: Size (in bytes) to be allocated for the character array.
* @error_message: Error message to be displayed in case of
* memory allocation failure.
*
* Return: Pointer to the allocated memory on success, or NULL on failure.
*/
char *allocate_memory_for_char(char **string, size_t size,
		char *error_message)
{
	*string = (char *)malloc(sizeof(char) * size);

	if (*string == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (*string);
}

/**
* allocate_memory_for_array - Allocate memory for an array of strings.
*
* Description: This function dynamically allocates memory for an array of
*              character pointers of given size.
*
* @array: Pointer to a pointer to char that will be updated to point to the
*             newly allocated memory.
* @size: Number of character pointers (elements) to be allocated
*                  for the array.
* @error_message: Error message to be displayed in case of
* memory allocation failure.
*
* Return: Pointer to the allocated memory on success, or NULL on failure.
*/
char **allocate_memory_for_array(char **array, size_t size,
		char *error_message)
{
	array = (char **)malloc(sizeof(char *) * size);
	if (array == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (array);
}

/**
* copy_tokens - Copy an array of strings.
*
* Description: This function copies an array of strings from the source to
*              the destination.
*
* @dest: Pointer to a pointer to char representing
* the destination array.
* @src: Pointer to a pointer to char representing the source array.
*
* Return: 0 on success, -1 on failure (memory allocation error).
*/
int copy_tokens(char **dest, char **src)
{
	size_t dest_index;
	size_t free_dest_index;

	for (dest_index = 0; src[dest_index]; dest_index++)
	{
		dest[dest_index] = strdup(src[dest_index]);
		if (dest[dest_index] == NULL)
		{
			perror("_setenv() Error: destination[dest_index] strdup failed");
			for (free_dest_index = 0; free_dest_index < dest_index;
					free_dest_index++)
				free(dest[free_dest_index]);
			free(dest);
			return (-1);
		}
	}
	return (0);
}

/**
* _env_variable_exists - Check if an environment variable name exists.
*
* Description: This function checks if a given environment variable
* name exists in the system's environment.
*
* @name: Pointer to a constant char containing the name of the
* environment variable to check.
*
* Return: Index where the match was found, or -1 if the name doesn't exist.
*/
int _env_variable_exists(const char *name)
{
	int env_i, match_index;

	match_index = -1;

	for (env_i = 0; __environ[env_i]; env_i++)
		if (strncmp(__environ[env_i], name, strlen(name)) == 0)
			match_index = env_i;

	return (match_index);
}

/**
* _env_length - Calculate the number of environment variables.
*
* Description: This function calculates the number of elements
* (environment variables) in the system's environment.
*
* Return: The number of environment variables.
*/
int _env_length(void)
{
	int len = 0;

	while (__environ[len])
		len++;

	return (len);
}
