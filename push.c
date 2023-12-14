#include "monty.h"
/**
 * push - adds a new node at the beginning
 * @head: pointer to pointer head
 * @n: data int
 * Return: the address of the new element, or NULL if it failed.
 */
void push(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		exit(EXIT_FAILURE);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
