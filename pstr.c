#include "monty.h"
void pstr(stack_t **head, unsigned int __attribute__ ((unused)) line_number)
{
    int ch = (*head)->n;
    stack_t *ptr = *head;

    while ((ch >= 0 || ch <= 127) && ptr)
    {
        ch = ptr->n;
        printf("%c", ch);
        ptr = ptr->next;
    }
    printf("\n");
 
}