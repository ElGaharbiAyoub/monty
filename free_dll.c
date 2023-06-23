#include "monty.h"

/**
 * free_stack - frees a dlistint_t list
 * @head: beginning of doubly linked list
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
