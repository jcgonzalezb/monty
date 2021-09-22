#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#define TOK_DELIM " \t\r\n\a\\$"

void push()
{
	printf("Aqui estoy\n");
}

void pall()
{
	printf("Por alla\n");
}

void pint()
{	
/*	if (h != NULL)
	{
		printf("%d\n", h->n);
	}
	else
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n", );
		exit(EXIT_FAILURE);	
	}
	
	*/

	printf("Es por aca\n");
}

void nop ()
{
	(void) printf;
	printf("nop is working\n");
}

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

void (*selectf(char **args))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
	/*	{"pop", pop},
		{"swap", swap},
		{"add", add},*/
		{"nop", nop},
		{NULL, NULL}
	};

	while (instruction_s[i].opcode != NULL)
	{
		if (strcmp(args[0], instruction_s[i].opcode) == 0)
		{
			return (instruction_s[i].f);
		}
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	char **args = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	void (*selector)();

	FILE *fp = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		/*printf("USAGE: monty file\n");*/
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		line_count++;
		/*printf("line count [%06d]\n", line_count);*/
		/*printf("%s\n", line_buf);*/
		args = tokenization(line_buf);
		if (args[0] == NULL)
		{
			free(args);
			free(line_buf);
			continue;
		}
		
/*		if (args[0] = "push")
		{
			if ((atoi(args[1]) >= 0 && atoi(args[1]) <= 9))
			{
				printf("%s\n", args[1]);
			}
		}
		else
			continue;*/

		/*printf("%s\n", *args);*/
		selector = selectf(args);
		if (selector != NULL)
		{
			selector();
			/*selector();*/
		}
		else
		{



		}
		/*line_size: Size of every line*/
		/*line_buf: Data in every line*/
		/*printf("%ld\n", line_size);*/
		/* Get the next line */
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf);
	line_buf = NULL;

	fclose(fp);

	return (EXIT_SUCCESS);
}
