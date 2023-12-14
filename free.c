#include "monty.h"
/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to head
 * Return: Always 0
 */
void free_dlistint(stack_t **head)
{
	if (*head == NULL)
		return;

	if ((*head)->next != NULL)
		free_dlistint(&(*head)->next);

	free(head);
}
