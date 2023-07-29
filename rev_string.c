#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
* reverse_string - cofunction to rever tsirng
* @s: string
*
*/
void reverse_string(char *s)
{
int j;
int i;
while (s[j] != '\0')
j++;

for (i = 0; i < j; i++, j--)
{
char tmp = s[i];
s[i] = s[j];
s[j] = tmp;
}
}

/**
* _integer_to_string - converts int to a string
* @num: number to convert
*
* Return: the converted string representation
*/
char *_integer_to_string(size_t num)
{
char *s = malloc(sizeof(char) * (32 + 1));
int i = 0;

while (num > 0)
{
s[i] = num % 10 + '0';
num /= 10;
i++;
}

s[i] = '\0';
reverse_string(s);

return (s);
}
