#include "main.h"

/**
 * free_main - free array of tokens in the main function
 * @array_of_tokens: tokenized string
 * @input: string
 *
 * Return: void
 */
void free_main(char **array_of_tokens, char *input)
{
	int index;

	for (index = 0; array_of_tokens[index]; index++)
		free(array_of_tokens[index]);
	free(array_of_tokens);
	free(input);
}

/**
 * free_which - describes short
 *
 * Description: describes long
 *
 * @path_var: describes argument_1 
 * @array_of_tokens: describes argument_2
 *
 * Return:  description return
 */
void free_which(char **path_var, char **array_of_tokens)
{
    int index = 0;

    if (array_of_tokens != NULL)
    {
        do
        {
            if (array_of_tokens[index] != NULL)
            {
                free(array_of_tokens[index]);
                index++; 
            }
        } while (array_of_tokens[index] != NULL);

        
        free(array_of_tokens);
    }


    if (*path_var != NULL)
        free(*path_var);
}
