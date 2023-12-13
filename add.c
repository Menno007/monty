#include "monty.h"
void add(stack_t **head, unsigned int line_number)
{
    stack_t *ptr = *head;
    int size = 0;

    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }

    if (size < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    ptr = *head;
    ptr->next->n += ptr->n;
    ptr = ptr->next;
    free(*head);
    *head = ptr;
    return;
}
