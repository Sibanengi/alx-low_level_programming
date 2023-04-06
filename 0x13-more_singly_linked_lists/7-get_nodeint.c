#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of a listint_t linked list
* @head: pointer to the head of the list
* @index: index of the node, starting at 0
*
* Return: pointer to the nth node, or NULL if the node does not exist
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i;
listint_t *n;

for (i = 0, n = head; n != NULL && i < index; i++, n = n->next)
;

if (n == NULL)
return (NULL);

return (n);
}
