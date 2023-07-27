#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prepare_and_execve(int argc, char **argv, char **env)
{
	char **argv2;
	int i = 0;    /** Check if argv[0] contains the path "/bin/" */

	if (argc > 0 && strncmp(argv[0], "/bin/", 5) == 0)
	{
		printf("The path is already specified in argv[0]: %s\n", argv[0]);
		return;
	}    /** Allocate memory for the double pointer argv2 */

	argv2 = (char **)malloc((argc + 1) * sizeof(char *));
	while (argv[i] != NULL)
	{
		size_t len = strlen(argv[i]);
		/** Allocate memory for each argument in argv2 */
		argv2[i] = (char *)malloc(len + 5);

		/** "+5" for "/bin/" and null terminator   if (i == 0) { */
		/** For the first argument (program path), prepend "/bin/" */
		strcpy(argv2[i], "/bin/");
		strcat(argv2[i], argv[i]);
	}
	else
	{
		/** For other arguments, copy them as they are */
		strcpy(argv2[i], argv[i]);
	}
	i++;
}
	/** The last element of argv2 should be NULL as required by execve */
	argv2[i] = NULL;    /** Now, you can call execve with the modified argv2 */
	execve(argv2[0], argv2, env);

	/** Free memory for each argument in argv2 */
	for (i = 0; argv2[i] != NULL; i++)
	{
		free(argv2[i]);
	}
/** Free memory for argv2 itself */

	free(argv2);
	}

int main(int argc, char **argv, char **env)
{
	prepare_and_execve(argc, argv, env);
	return (0);
}

