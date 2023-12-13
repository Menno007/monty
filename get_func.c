#include "monty.h"
/**
 * get_op_func - function pointer that selects the correct function to perform
 * the operation asked by the user
 * @s: the operator given by the user
 *
 * Return: pointer to the function that corresponds to the
 * operator given as a parameter
 */
void (*get_func(char *s, int line_number))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
    {"pall", pall},
	{"pint", pint},
	{"pop", pop},
    {NULL, NULL}
};

	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcodes[i].opcode, s) == 0)
            return opcodes[i].f;
    }

	if (opcodes[i].f == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
        exit(EXIT_FAILURE);
    }
	return (NULL);
}