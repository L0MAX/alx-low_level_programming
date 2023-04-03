#include "lists.h"

/**
 * print_listint - a function that prints all the elements of a listint_t
 * list.
 * @h: a pointer to the first node of the list
 * Return: returns the number of nodes printed
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *ptr = h;
	size_t counrt = 0;

	if (!h)
		return (0);

	while (ptr)
	{
		counrt++;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	return (counrt);
}
