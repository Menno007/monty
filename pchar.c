#include "monty.h"
void pchar(stack_t **head, unsigned int line_number)
{
    int ch = (*head)->n;

    if ((*head) == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (ch < 0 || ch > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", ch);
}