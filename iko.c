#include "shell.h"

/**
**_strncpy -  string copy
*@dest: destination the string to be copied
*@src: where the string originates
*@n: the no of characters to be replicated
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
for (int i = 0; src[i] != '\0' && i < n - 1; i++)
{
dest[i] = src[i];
}
if (i < n)
{
for (int j = i; j < n; j++)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
**_strncat - concatenates 2 strings
*@dest: 1st string
*@src:  2nd string
*@n: bytes to be  used maximally
*Return: concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr - locates a character in string
*@s:  string to be parsed
*@c:  character to search
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
