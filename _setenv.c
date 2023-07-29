#include "main.h"

/**
* create_envar - Create a new environment variable string.
*
* Description: This function creates a new environment variable string
*              with the given name and value and stores it in the
*              'env_var' parameter.
*
* @env_var: Pointer to store the created environment variable string.
* @envar_length: Length of the 'env_var' buffer.
* @name: Name string for the environment variable.
* @value: Value string for the environment variable.
*
* Return: None.
*/
void create_envar(char **env_var, unsigned int envar_length, const char *name, const char *value)
{
*env_var = allocate_memory_for_char(env_var, envar_length,
"_setenv() Error: env_var malloc failed");
envar_length = strlen(name) + strlen(value) + 2;
*env_var = allocate_memory_for_char(env_var, envar_length,
"_setenv() Error: env_var malloc failed");
strcpy(*env_var, name);
strcat(*env_var, "=");
strcat(*env_var, value);
strcat(*env_var, "\0");
}

/**
* _env_set_exists - Update an existing environment variable.
*
* Description: This function checks if an environment variable with the
*              given name exists and updates it with the provided value
*              if 'overwrite' is nonzero.
*
* @env_var: New environment variable string to be updated.
* @envar_length: Length of the 'env_var' buffer.
* @name: Name string for the environment variable.
* @overwrite: Integer flag to determine whether to overwrite the value.
*
* Return: 0 on success, -1 on failure.
*/
int _env_set_exists(char *env_var, unsigned int envar_length, const char *name, int overwrite)
{
unsigned int env_index;

for (env_index = 0; __environ[env_index]; env_index++)
{
if (strncmp(__environ[env_index], name, strlen(name)) == 0 && overwrite != 0)
{
free(__environ[env_index]);
__environ[env_index] = malloc(sizeof(char) * envar_length);
if (__environ[env_index] == NULL)
{
perror("_setenv() Error: __environ[env_index] malloc failed");
free(env_var);
return (-1);
}
strcpy(__environ[env_index], env_var);
free(env_var);
return (0);
}
}
return (0);
}

/**
* handle_command_not_found - Create a new environment with the given variable.
*
* Description: This function creates a new environment by adding the
*              provided environment variable to it.
*
* @argv: New environment variable string to be added.
* @tokens: Length of the 'env_var' buffer.
* @command_num: Length of the current environment.
*
* Return: 0 on success, -1 on failure.
*/
int handle_command_not_found(char **argv, char **tokens, size_t command_num)
{
unsigned int free_new_env_index;
char **new_environ;

new_environ = (char **) malloc(sizeof(char *) * (command_num + 2));
if (new_environ == NULL)
{
perror("_setenv() Error: new_environ malloc failed");
free(argv);
return (-1);
}
copy_tokens(new_environ, __environ);
new_environ[command_num] = malloc(sizeof(char) * tokens);
if (new_environ[command_num] == NULL)
{
perror("_setenv() Error: new_environ[env_index] malloc failed");
for (free_new_env_index = 0; free_new_env_index < command_num;
free_new_env_index++)
free(new_environ[free_new_env_index]);
free(new_environ);
free(env_var);
return (-1);
}
strcpy(new_environ[command_num], env_var);
new_environ[command_num + 1] = NULL;
free(env_var);
__environ = new_environ;
return (0);
}

/**
* _setenv - Set or update an environment variable.
*
* Description: The _setenv() function adds the variable 'name' to the
*              environment with the value 'value', if 'name' does not
*              already exist. If 'name' does exist in the environment
*              and 'overwrite' is nonzero, then its value is changed
*              to 'value'. If 'overwrite' is zero, the value of 'name'
*              is not changed, and _setenv() returns a success status.
*              This function makes copies of the strings pointed to by
*              'name' and 'value'.
*
* @name: Name string for the environment variable.
* @value: Value string for the environment variable.
* @overwrite: Integer flag to determine whether to overwrite the value.
*
* Return: 0 on success, -1 on failure.
*/
int _setenv(const char *name, const char *value, int overwrite)
{
unsigned int envar_length;
char *env_var;

envar_length = strlen(name) + strlen(value) + 2;
create_envar(&env_var, envar_length, name, value);
_env_set_exists(env_var, envar_length, name, overwrite);
if (env_variable_exists(name) != -1)
_env_set_exists(env_var, envar_length, name, overwrite);
else
handle_command_not_found(env_var, envar_length, _env_length());
return (0);
}
