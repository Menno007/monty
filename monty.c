#include "monty.h"
#include <string.h>
int main(int argc, char **argv)
{
    unsigned int line_number = 0;
    size_t BufferSize = 0;
    char *line = NULL, *token = NULL;
    FILE *monty_file = NULL;
    stack_t *head = NULL;
    void (*f)(stack_t **, unsigned int);
    if (argc != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    if (monty_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }



    while (getline(&line, &BufferSize, monty_file) != -1)
    {
        line_number++;
        token = strtok(line, " \t\n");
        if (token == NULL || token[0] == '#')
            continue;

        f = get_func(token, line_number);
        f(&head, line_number);
    }




     /* Close the file */
    fclose(monty_file);

    /* Free the allocated memory */
    if (line != NULL) {
        free(line);
    }

    return 0;
}

