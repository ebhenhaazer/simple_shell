#include "main.h"

/**
* _getenv - Retrieve the value of an environment variable.
*
* Description: This function retrieves the value of an environment variable
*              based on its name.
*
* @name: Name of the environment variable.
*
* Return: If the environment variable is found, a pointer to its value is
*         returned. If the variable is not found or on failure, NULL is returned.
*/
char *_getenv(const char *name)
{
unsigned int env_index;
size_t name_length = strlen(name);

for (env_index = 0; __environ[env_index]; env_index++)
{
if (strncmp(__environ[env_index], name, name_length) == 0 && __environ[env_index][name_length] == '=')
{
char *env_var_value = __environ[env_index] + name_length + 1;
return env_var_value;
}
}
return NULL;
}

malloc_str(&env_var_cpy, strlen(__environ[env_index]) + 1,
"_getenv() malloc error");
strcpy(env_var_cpy, __environ[env_index]);
strncpy(env_var, env_var_cpy += (strlen(name) + 1), envar_length);
free(env_var_cpy -= (strlen(name) + 1));
return (env_var);
}
}
return (NULL);
}
