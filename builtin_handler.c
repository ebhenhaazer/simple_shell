#include "main.h"

/**
* builtin_handler - Check if the command is a built-in and execute it.
*
* Description: This function checks if the command provided in the
*               array_of_tokens is a built-in command. If it is, it
*               calls the corresponding built-in function and returns
*               its return value. If not, it returns 0.
*
* @array_of_tokens: Command array.
*
* Return: The return value of the built-in function if it is executed,
*         or 0 if the command is not a built-in.
*/
int builtin_handler(char **array_of_tokens)
{
int builtin_index;
const struct builtin_command builtins[] = {
{"env", _print_env},
{"exit", _exit_builtin},
{NULL, NULL}
};

if (array_of_tokens == NULL || array_of_tokens[0] == NULL)
return (0);

for (builtin_index = 0; builtins[builtin_index].name != NULL; builtin_index++)
{
if (strcmp(array_of_tokens[0], builtins[builtin_index].name) == 0)
return builtins[builtin_index].function(array_of_tokens);
}

return (0);
}

/**
* builin_handler - short description
*
* Description: long description
*
* @array_of_tokens: command array
*
* Return: 1 if success 0 if failure
*/
int builin_handler(char **array_of_tokens)
{
int builtin_index;
const struct builtin_command builtins[] = {
{"env", is_builtin},
{"exit", exit_builtin},
{NULL, NULL}
};

if (array_of_tokens == NULL)
return (0);
if (array_of_tokens[0] == NULL)
return (0);

for (builtin_index = 0; builtins[builtin_index].name != NULL;
builtin_index++)
{
if (strcmp(array_of_tokens[0],
builtins[builtin_index].name) == 0)
return (builtins[builtin_index].function(array_of_tokens));
}
return (0);
}
