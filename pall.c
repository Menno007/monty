#include "monty.h"
void pall(stack_t **head, unsigned int line_number)
{
    const stack_t *ptr = *head;
    (void)line_number;

	while (ptr)
    {
		printf("%d\n", ptr->n);
        ptr = ptr->next;
	}
    return;
}