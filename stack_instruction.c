#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
void push(stack_t **head, unsigned int line_number)
{
	int n1;
	char *n = strtok(NULL, " \t\n");
	stack_t *new_node, *ptr = *head;

	if (!n || !check_intger(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free(head), free(n), free(G.monty_file), free(G.line);
		exit(EXIT_FAILURE);
	}

	n1 = atoi(n);
	new_node = malloc(sizeof(*head));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(head), free(n), free(G.monty_file);
		exit(EXIT_FAILURE);
	}

	if (*head == NULL)
	{
		new_node->n = n1;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}


	else
	{
		ptr->prev = new_node;
		new_node->next = ptr;
		new_node->prev = NULL;
		new_node->n = n1;
		*head = new_node;
	}

}

/**
 * pop - removes the top element of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction
*/
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
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @head: Pointer to head.
 * @line_number: Line number of instruction.
*/
void pall(stack_t **head, unsigned int line_number)
{
	const stack_t *ptr = *head;
	(void)line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * check_intger - To check whether the given string
 *  contains a character or not.
 * @data: Pointer to string.
 * Return: 1 if string only numbers else 0.
*/
int check_intger(char *data)
{
	int i = 0, n = strlen(data);

	if (!data)
		return (0);

	if (data[0] == '-')
		i++;

	for (; i < n; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return (0);
	}

	return (1);
}