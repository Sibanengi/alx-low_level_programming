#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: pointer to a pointer to the head of the list
*
* @n: integer value to be stored in the new node
*
* Return: the address of the new element, or NULL if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *temp;

/* allocate memory for the new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* initialize the new node */
new_node->n = n;
new_node->next = NULL;

/* if the list is empty, make the new node the head */
if (*head == NULL)
{
*head = new_node;
return (new_node);
}

/* traverse the list to find the last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* add the new node to the end of the list */
temp->next = new_node;

return (new_node);
}
