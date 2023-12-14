#include "monty.h"
int main(int argc, char *argv[]);
/**
 * main - function
 * @argc: ll
 * @argv: ll
 * Return: ll
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char opcode[256];
	unsigned int line_number = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
