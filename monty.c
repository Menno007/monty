#include "monty.h"
#include <string.h>
global_t G;

int main(int argc, char **argv)
{
    unsigned int line_number = 0;
    size_t BufferSize = 0;
    char *token = NULL;
    stack_t *head = NULL;
    void (*f)(stack_t **, unsigned int);

    if (argc != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
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
        token = strtok(G.line, " \t\n");
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

