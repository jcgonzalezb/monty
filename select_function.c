#include "monty.h"

void (*selectf(char **args))(char **args, char *line)
{
    int i = 0;

    order options[] = {
        {"push", _push},
        {"pall", pall},
        {NULL, NULL}};

    while (options[i].program != NULL)
    {
        if (strcmp(args[0], options[i].program) == 0)
        {
            printf("%s %s\n", args[0], options[i].program);
            return (options[i].f);
        }
        i++;
    }
    return (NULL);
}