#include "monty.h"
#include <string.h>
#include <stdio.h>
global_t G;

/**
 * main - main function
 *
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 (always success)
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	size_t BufferSize = 0;
	char *token = NULL;
	stack_t *head = NULL;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	G.monty_file = fopen(argv[1], "r");
	if (G.monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&G.line, &BufferSize, G.monty_file) != -1)
	{
		line_number++;
		token = strtok(G.line, "\t\n ");
		if (token == NULL || token[0] == '#')
			continue;

		f = get_func(token, line_number);
		f(&head, line_number);
	}

	free(G.line);
	fclose(G.monty_file);
	_free(&head);

	exit(EXIT_SUCCESS);
}

/**
 * get_func - function pointer that selects the correct function to perform
 * the instruction that reading from file
 * @s: the operator given by the user
 * @line_number: Line number of instruction
 * Return: pointer to the function that corresponds to the
 * operator given as a parameter
 */
void (*get_func(char *s, int line_number))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
	{"push", push}, {"pall", pall},
	{"pint", pint}, {"pop", pop},
	{"swap", swap}, {"add", add},
	{"nop", nop}, {"sub", sub},
	{"div", divf}, {"mul", mul},
	{"mod", mod}, {"pchar", pchar},
	{"pstr", pstr}, {"rotl", rotl},
	{NULL, NULL}
};

	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
	}

	if (opcodes[i].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
		free(s), free(G.monty_file);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
