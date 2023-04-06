#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* find_listint_loop - finds the node where a loop starts in a linked list
* @head: pointer to the head of the list
*
* Return: the address of the node
* where the loop starts, or NULL if there is no loop
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head, *fast = head;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}

return (NULL);
}
