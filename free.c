#include "monty.h"
/**
 * free_dlistint - to Free the All list.
 * @head: head of linked list.
 */
void _free(stack_t **head)
{
	stack_t *next;

	if (*head == NULL)
		return;

	while (next)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}