#include "monty.h"
/**
 * swap_f - Swaps the top two elements of a stack.
 * @head: Pointer to a pointer to the head of the stack.
 * @line: Line number of the swap command.
 */
void swap_f(stack_t **head, unsigned int line)
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
 * add_f - Adds the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line: Line number where the add function is called.
 *
 * Description: This function adds the top two elements of the stack and
 * replaces the top element with the sum. The second element is removed
 * from the stack.
 */

void add_f(stack_t **head, unsigned int line)
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
 * nop_f - Does nothing.
 * @head: void.
 * @line: void.
 */
void nop_f(stack_t **head, unsigned int line)
{
	(void)*head;
	(void)line;
}
/**
 * sub_f - Subtracts the top element of the stack from the second top element.
 * @head: Double pointer to the head of the stack.
 * @line: Line number where the sub_f function is called.
 *
 * Description: This function subtracts the top element of the stack from the
 * second top element and replaces the second top element with the difference.
 * The top element is then removed from the stack.
 */
void sub_f(stack_t **head, unsigned int line)
{
	if (!head || !*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop_f(head, line);
}
/**
 * div_f - Divides the second top element of the stack by the top element.
 * @head: Double pointer to the head of the stack.
 * @line: Line number where the div_f function is called.
 * Description: This function divides the
 * second top element of the stack by the
 * top element and replaces the second top element with the quotient. The top
 * element is then removed from the stack. Handles division by zero.
 */
void div_f(stack_t **head, unsigned int line)
{
	if (!head || !*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		free_stack(*head);
		fprintf(stdout, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	pop_f(head, line);
}
