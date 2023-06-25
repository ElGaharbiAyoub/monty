#include "monty.h"
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

/**
 * add - Adds the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line: Line number where the add function is called.
 *
 * Description: This function adds the top two elements of the stack and
 * replaces the top element with the sum. The second element is removed
 * from the stack.
 */

void add(stack_t **head, unsigned int line)
{
	stack_t *top, *second;

	if (!head || !*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second = top->next;
	top->n += second->n;
	top->next = second->next;
	if (second->next)
		second->next->prev = top;
	free(second);
}
/**
 * nop - Does nothing.
 * @stack: Unused.
 * @line_n: Unused.
 */
void nop(stack_t stack, unsigned int line)
{
	UNUSED(stack);
	UNUSED(line);
}