#include "monty.h"
void pint(stack_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d", (*head)->n);
    return;
}