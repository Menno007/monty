#include "monty.h"
void rotl(stack_t **head, unsigned int __attribute__ ((unused)) line_number)
{
    stack_t *fast = *head, *slow = (*head);

    *head = (*head)->next;
    while (fast->next)
        fast = fast->next;

    slow->next = NULL;
    fast->next = slow;
    (*head)->prev = NULL;

}