#include "monty.h"

/** argc_validator valida que la cantidad de
 * argumentos ingresados por consola sean
 * solo dos, que son el nombre del  ejecutable
 * y el mombre del archivo a leer, si no son
 * dos muestra un error y termina el programa*/
void argc_validator(int argc)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
}

void _isdigit(char *args, int line_count)
{
    if(args == NULL)
    {
        fprintf(stderr, "L %i: usage: push integer\n", line_count);
        exit(EXIT_FAILURE);
    }
    if(args!= NULL)
    {
        printf("%s", args);
    }
}
