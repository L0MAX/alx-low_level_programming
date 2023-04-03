#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Print elements of a singly linked list.
 * @h: Pointer to a list.
 * Return: the number of nodes.
 **/

size_t print_listint(const listint_t *h)
{
	const listint_t *dona;
	unsigned int countr = 0;

	dona = h;
	while (dona)
	{
		printf("%d\n", dona->n);
		countr++;
		dona = dona->next;
	}
	return (countr);
}
