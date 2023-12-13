#include "monty.h"
void swap(stack_t **head, unsigned int line_number)
{
    stack_t *ptr = *head;
    size_t size = 0;

    while (ptr)
    {
        size++;
        ptr = ptr->next;
    }

    if (size < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    
    return;
}