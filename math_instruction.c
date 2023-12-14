#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void add(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0;

	while (ptr != NULL)
		size++, ptr = ptr->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	ptr->next->n += ptr->n;
	ptr = ptr->next;
	free(*head);
	*head = ptr;
}

/**
 * divf - divides the second top element of the stack
 * by the top element of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void divf(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0;

	while (ptr != NULL)
		size++, ptr = ptr->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	ptr->next->n /= ptr->n;
	ptr = ptr->next;
	free(*head);
	*head = ptr;
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0;

	while (ptr != NULL)
		size++, ptr = ptr->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	ptr->next->n %= ptr->n;
	ptr = ptr->next;
	free(*head);
	*head = ptr;
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0;

	while (ptr != NULL)
		size++, ptr = ptr->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	ptr->next->n *= ptr->n;
	ptr = ptr->next;
	free(*head);
	*head = ptr;
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;
	int size = 0;

	while (ptr != NULL)
		size++, ptr = ptr->next;

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	ptr->next->n -= ptr->n;
	ptr = ptr->next;
	free(*head);
	*head = ptr;
}
