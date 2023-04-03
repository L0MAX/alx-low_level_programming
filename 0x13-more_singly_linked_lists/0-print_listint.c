#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - function that prints all the elements of a list.
 * @h : is the head of list.
 * Return: the number of nodes.
 */

size_t print_listint(const listint_t *h)
{
	size_t length = 0;

	while (h)
	{
		printf("%d\n", h->n);
		length++;
		h = h->next;
	}
	return (length);
}
