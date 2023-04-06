#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* print_listint_safe - prints a listint_t linked list
* @head: pointer to the head of the list
*
* Return: the number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current = head, *temp;
size_t count = 0;

while (current != NULL)
{
printf("[%p] %d\n", (void *)current, current->n);
count++;

temp = current;
current = current->next;

if (temp <= current)
{
printf("-> [%p] %d\n", (void *)current, current->n);
count++;
break;
}
}

return (count);
}
