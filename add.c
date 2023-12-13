#include "monty.h"
void add(stack_t **head, unsigned int line_number)
{
    stack_t *ptr = *head;
    int size = 0, tmp;

    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }

    if (size < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        _free(head), free(G.monty_file), free(G.line);
        exit(EXIT_FAILURE);
    }

    ptr = *head;
    ptr->next->n = ptr->next->n + ptr->n;
    *head = (*head)->next;
    free(ptr);
    ptr = NULL;

    return;
}
