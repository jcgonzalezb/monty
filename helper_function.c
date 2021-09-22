#include "monty.h"

char **tokenization(char *line)
{
    char *token;
    int p = 0;
    char **tokens = malloc(sizeof(char *) * 1024);

    if (!tokens)
        exit(EXIT_SUCCESS);

    token = strtok(line, TOK_DELIM);

    while (token != NULL)
    {
        tokens[p] = token;
        p++;
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[p] = NULL;
    return (tokens);
}
