#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* sum_listint - returns the sum of all the data (n) of a listint_t linked list
* @head: pointer to the head of the list
*
* Return: sum of all the data in the list, or 0 if the list is empty
*/
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *m;

for (m = head; m != NULL; m = m->next)
sum += m->n;

return (sum);
}
