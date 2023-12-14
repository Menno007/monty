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
	stack_t *stack = NULL;
	FILE *byte_code_file;
	char *opcode[256];
	int i, value, line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	byte_code_file = fopen(argv[1], "r");
	if (byte_code_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(byte_code_file, "%s", opcode) != EOF)
	{
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				if (strcmp(opcode, "push") == 0)
				{
					if (fscanf(byte_code_file, "%d", &value) != 1)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						return (EXIT_FAILURE);
					}
				}
				instructions[i].f(&stack, line_number);
				break;
			}
		}
	}
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
		return (EXIT_FAILURE);
	}
	fclose(byte_code_file);
	return (EXIT_SUCCESS);
}
