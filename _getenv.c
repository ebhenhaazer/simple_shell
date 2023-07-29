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

            char *env_var = malloc(strlen(env_var_value) + 1);
            if (env_var == NULL)
            {
                perror("_getenv() Error: env_var malloc failed");
                return NULL;
            }

            strcpy(env_var, env_var_value);
            return env_var;
        }
    }

    return NULL;
}

