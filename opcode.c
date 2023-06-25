#include "monty.h"

/**
 * push - Add a new node to the top of the stack.
 * @head: Pointer to the head of the stack.
 * @n: The value to be stored in the new node.
 *
 * Return: Pointer to the newly added node.
 */
stack_ty *push(stack_ty **head, int n)
{
	stack_ty *new;

	new = malloc(sizeof(stack_ty));
	if (!new)
	{
		if (*head != NULL)
			free_stack(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * pall - Print all elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line: The line number in the input file.
 */
void pall(stack_ty **head, unsigned int line)
{
	stack_ty *h = *head;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	for (; h; h = h->next)
		fprintf(stdout, "%d\n", h->n);
}
/**
 * pint - Print the value at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @line: The line number in the input file.
 */
void pint(stack_ty **head, unsigned int line)
{
	stack_ty *h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", h->n);
}
/**
 * pop - Remove the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line: The line number in the input file.
 */
void pop(stack_ty **head, unsigned int line)
{
	stack_ty *dlt = *head;

	if (!dlt)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	*head = dlt->next;
	free(dlt);
}
/**
 * swap - Swaps the top two elements of a stack.
 * @head: Pointer to a pointer to the head of the stack.
 * @line: Line number of the swap command.
 */
void swap(stack_t **head, unsigned int line)
{
	int tmp;

	if (!head || !*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
