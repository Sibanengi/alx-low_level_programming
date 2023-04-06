#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
* free_listint_safe - frees a listint_t list
* @h: pointer to the head of the list
*
* Return: the size of the list that was free'd
*/
size_t free_listint_safe(listint_t **h)
{
listint_t *current = *h, *temp;
size_t count = 0;

while (current != NULL)
{
count++;

temp = current;
current = current->next;

free(temp);

if (temp <= current)
{
*h = NULL;
break;
}
}

return (count);
}
