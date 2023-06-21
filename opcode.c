#include "monty.h"

stack_t *push(stack_t **head, int n)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (!new)
        return (NULL);

    new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}


void pall( stack_t **head, unsigned int line)
{
    stack_t *h = *head;
    if (!h)
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	for (; h; h = h->next)
		fprintf(stdout, "%d\n", h->n);
}

void pint( stack_t **head, unsigned int line)
{
    stack_t *h = *head;
    if (!head)
    {
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%d\n", h->n);
}

void pop(stack_t **head, unsigned int line)
{
    stack_t *dlt = *head;

    if (!dlt)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
    }
    *head = dlt->next;
    free(dlt);
}
