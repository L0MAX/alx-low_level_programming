#include "main.h"

/**
 * set_bit - the value of a bit to 1 at a given index.
 * @index: starting from 0 of the bit you want to set
 * @n: pointer number of dona
 * L0MAX
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int dona;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	dona = 1 << index;
	*n = *n | dona;

	return (1);
}

