#include "monty.h"
/**
 * get_op_func - function pointer that selects the correct function to perform
 * the operation asked by the user
 * @s: the operator given by the user
 *
 * Return: pointer to the function that corresponds to the
 * operator given as a parameter
 */
void (*get_func(char *s))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
    {"pall", pall},
    {"pint", pint},
    // ... other opcodes ...
    {NULL, NULL} // terminator
};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}