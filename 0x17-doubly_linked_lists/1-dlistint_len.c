#include "lists.h"

/**
 * dlistint_len - A function that gets the length of the list
 * @h: The head of the list
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
int res = 0;
while (h != NULL)
{
res++;
h = h->next;
}
return (res);
}
