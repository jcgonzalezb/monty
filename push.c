#include "monty.h"


stack_s _push (stack_s **head, const int n)
{
	stack_s *new_node;

	new_node = malloc(sizeof(stack_s));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (head == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
	}

	if ((*head) != NULL)
		(*head)->prev = new_node;

	(*head) = new_node;

	return (new_node);
	
}
