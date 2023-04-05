#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* pop_listint - deletes the head node of a listint_t linked list
* @head: pointer to the head of the list
*
* Return: the head node's data (n), or 0 if the list is empty
*/
int pop_listint(listint_t **head)
{
listint_t *temp;
int data;

/* check if the list is empty */
if (*head == NULL)
return (0);
data = (*head)->n;

/* delete the head node */
temp = *head;
*head = (*head)->next;
free(temp);

return (data);
}
