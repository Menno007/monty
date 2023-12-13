#include "monty.h"
void push(stack_t **head, unsigned int line_number, char *data)
{
    int n;
    stack_t *new_node, *ptr = *head;

    if (!check_intger(data))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(data);
	new_node = malloc(sizeof(*head));
	if (new_node == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
        free(*head), free(data);
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
    int i = 0, n = strlen(data);

    if (!data)
        return (0);
    
    if (data[0] == '-')
        i++;
    for (i; i < n-1; i++)
    {
        if (data[i] < '0' || data[i] > '9')
            return (0);
    }

    return (1);
}