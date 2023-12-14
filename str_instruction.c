#include "monty.h"
/**
 * pchar -  Prints the char at the top of the stack, followed by a new line.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;

	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free(head), free(G.line), free(G.monty_file);
		exit(EXIT_FAILURE);
	}

	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free(head), free(G.line), free(G.monty_file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ptr->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 *  followed by a new line.
 * @head: pointer to head.
 * @line_number: line number of instruction.
*/
void pstr(stack_t **head, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *ptr = *head;

	if (!ptr)
		return;

	while ((ptr->n > 0 && ptr->n < 127) && ptr)
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}

	printf("\n");

}

/**
 * nop - doesn’t do anything.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

}
