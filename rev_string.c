#include <stdlib.h>
#include <stdio.h>

/**
* _integer_to_string - converts int to a string
* @num: number to convert
*
* Return: the converted string representation
*/
char *_integer_to_string(size_t num)
{
	/* Determine the number of digits in the integer */
	size_t temp = num;
	int num_digits = 0;

	do {
		num_digits++;
		temp /= 10;
	} while (temp > 0);

	/* Allocate memory for the string representation */
	char *str = (char *)malloc((num_digits + 1) * sizeof(char));

	if (str == NULL)
	{
		printf("Memory allocation failed!\n");
		return (NULL);
	}

	/* Convert the integer to its ASCII characters */
	str[num_digits] = '\0';

	for (int i = num_digits - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}

	return (str);
}

/**
* main - Entry point
*
* Return: 0 if success
*/
int main(void)
{
	size_t number = 1234;
	char *str = _itoa(number);

	if (str != NULL)
	{
		printf("Integer: %zu\nString: %s\n", number, str);
		free(str); /* Don't forget to free the allocated memory */
	}
	return (0);
}
