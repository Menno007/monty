#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void rotl(stack_t **head, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *fast = *head, *slow = (*head);

	*head = (*head)->next;
	while (fast->next)
		fast = fast->next;

	slow->next = NULL;
	fast->next = slow;
	(*head)->prev = NULL;

}
