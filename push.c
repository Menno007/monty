#include "monty.h"
/**
 * push - adds a new node at the beginning
 * @stack: pointer to pointer head
 * @value: data int
 * @line_number: msccw
 * Return: the address of the new element, or NULL if it failed.
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
