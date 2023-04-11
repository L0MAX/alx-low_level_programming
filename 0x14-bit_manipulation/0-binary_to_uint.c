#include "main.h"

/**
 * binary_to_uint -converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 * L0MAX
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int dona;
	unsigned int joe;

	joe = 0;
	if (!b)
		return (0);
	for (dona = 0; b[dona] != '\0'; dona++)
	{
		if (b[dona] != '0' && b[dona] != '1')
			return (0);
	}
	for (dona = 0; b[dona] != '\0'; dona++)
	{
		joe <<= 1;
		if (b[dona] == '1')
			joe += 1;
	}
	return (joe);
}
