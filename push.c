#include "monty.h"

/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * push - adds node to the start of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (is_number(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * add_end_node - add node to front of doubly linked list
 * @h: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *new;

	if (!h)
		return (-1);

	/* malloc and set new node data */
	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	new->n = n;

	/* account for empty linked list */
	if (*h == NULL)
	{
		*h = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else /* insert to front */
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (0);
}

/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @h: pointer to head of list
 */
void free_dlist(stack_t **h)
{
	/* return if empty list */
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
