#include "monty.h"
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
    return;
}
