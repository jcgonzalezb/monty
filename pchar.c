#include "monty.h"

/**
 * pchar - print top node in stack as ascii letter
 * @h: head of list
 * @line_number: bytecode line number
 */
void pchar(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*h)->n) >= 0 && ((*h)->n) <= 127)
		printf("%c\n", (*h)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
