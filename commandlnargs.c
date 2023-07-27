#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Main - Entry point
 * @name: of code
 * @_getenv: return ent
 *
 * return: void
 */

char *_getenv(const char *name);
int _strcmp(const char *s1, const char *s2);

/**
 * Main - Entry point
 *
 * Return: void
 */
int main(void)
{
	char *s1, *s2, *s3;

	s1 = _getenv("PATH");
	s2 = _getenv("HOME");
	s3 = _getenv("PWD");

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
}

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i]
				return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * Loop through env
 * for each tokenize to get the name
 * and compare with input
 * if it matches - tokenize with '\0' RETURN RESULT ELSE RETURN NULL;
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char *token, *result, *copy;
	int i = 0;

	while (environ[i])
	{
		copy = strdup(environ[i]);
		token = strtok(copy, "=");


		if (_strcmp(token, name) == 0)
		{
			result = strtok(NULL, "\0");
			free(copy);
			return (result);
		}
		free(copy);
		i++;
	}
	return (NULL);
}

