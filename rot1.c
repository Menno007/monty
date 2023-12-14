#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void rotl(stack_t **head, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *fast = *head, *slow = (*head);

	if (!*head || !(*head)->next)
		return;

	*head = (*head)->next;
	while (fast->next)
		fast = fast->next;

	(*head)->prev = NULL;
	slow->next = NULL;
	slow->prev = fast;
	fast->next = slow;

}
