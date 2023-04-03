#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 *
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d", h->n);
        count++;

        if (h->next != NULL)
            printf("\n");

        h = h->next;
    }

    return (count);
}

