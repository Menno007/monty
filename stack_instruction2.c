#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0, tmp;

	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free(head), free(G.monty_file), free(G.line);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	tmp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = tmp;
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * _free - to Free the All list.
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
