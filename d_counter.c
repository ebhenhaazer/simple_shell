#include "main.h"

/**
* digits - Counts the number of digits in a given number.
* @num: The number to be counted.
*
* Return: The number of digits in the given number.
*/
int digits(size_t num)
{
	int num_of_digits = 0;

	/* Special case: If the number is 0, it has only one digit (0). */
	if (num == 0)
		return (1);

	/* Loop to count the digits in the number */
	for (; num != 0; num /= 10)
	{
		num_of_digits++;
	}

	return (num_of_digits);
}
