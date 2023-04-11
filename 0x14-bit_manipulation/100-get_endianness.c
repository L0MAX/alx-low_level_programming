#include "main.h"
/**
 * get_endianness - checks the endianness
 * L0MAX
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int edze;
	char *c;

	edze = 1;
	c = (char *)&edze;

	return (*c);
}

