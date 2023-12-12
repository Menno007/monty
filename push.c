#include "monty.h"
void push(stack_t **head, unsigned int line_number, char *data)
{
    int n;
    stack_t *new_node, *ptr = *head;

    if (!check_intger(data))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(data);
	new_node = malloc(sizeof(*head));
	if (new_node == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

	if (*head == NULL)
	{
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}


	else
	{
		ptr->prev = new_node;
		new_node->next = ptr;
		new_node->prev = NULL;
		new_node->n = n;
		*head = new_node;
	}

    return;
}

int check_intger(char *data)
{
    int i, n = strlen(data);

    if (data == NULL)
        return (0);
    for (i = 0; i < n-1; i++)
    {
        if (data[i] < '0' || data[i] > '9')
            return (0);
    }

    return (1);
}