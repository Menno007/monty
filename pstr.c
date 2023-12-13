#include "monty.h"
void pstr(stack_t **head, unsigned int line_number)
{
    int ch = (*head)->n;
    stack_t *ptr = *head;

    if ((*head) == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    while ((ch >= 0 || ch <= 127) && ptr && ptr->n != 0)
    {
        ch = ptr->n;
        printf("%c", ch);
        ptr = ptr->next;
    }
    printf("\n");
 
}