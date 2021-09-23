#include "monty.h"
/**
 * pop - removes node at front of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}

/**
 * delete_end_node - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{

		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
