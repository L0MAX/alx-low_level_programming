#include "main.h"
/**
 * _power - calculate (base and power)
 * @base: base of the exponent
 * @pow: power of the exponent
 * L0MAX
 * Return: value of base and power
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int number;
	unsigned int edze;

	number = 1;
	for (edze = 1; edze <= pow; edze++)
		number *= base;
	return (number);
}
/**
 * print_binary - prints the binary representation of a number
 * @n: num of parented
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int donas, results;
	char flag;

	flag = 0;
	donas = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (donas != 0)
	{
		results = n & donas;
		if (results == donas)
		{
			flag = 1;
			_putchar('1');

		}
		else if (flag == 1 || donas == 1)
		{
			_putchar('0');
		}
		donas >>= 1;
	}
}

