#include "monty.h"
void pop(stack_t **head, unsigned int line_number)
{
    stack_t *tmp = NULL;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        _free(head), free(G.monty_file), free(G.line);
        exit(EXIT_FAILURE);
    }

    tmp = *head;
    *head = tmp->next;
    free(tmp);
    return;
}