#include "main.h"
/**
 * flip_bits - flip to get from one number to another.
 * @n: the first number
 * L0MAX
 * @m: the second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference, result;
	unsigned int edze, dona;

	edze = 0;
	result = 1;
	difference = n ^ m;
	for (dona = 0; dona < (sizeof(unsigned long int) * 8); dona++)
	{
		if (result == (difference & result))
			edze++;
		result <<= 1;
	}

	return (edze);
}
