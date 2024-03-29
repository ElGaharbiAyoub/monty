#include "monty.h"
/**
 * mul_f - Multiplies the second top element of the stack with the top element
 * @head: Double pointer to the head of the stack
 * @line: Line number
 *
 * Description: If the stack contains less than two elements, prints an error
 * message and exits. Otherwise, multiplies the second top element with the top
 * element and removes the top element from the stack.
 */
void mul_f(stack_t **head, unsigned int line)
{
	if (!head || !*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop_f(head, line);
}
/**
 * mod_f - Computes the remainder of the division of the second top element
 *        by the top element of the stack
 * @head: Double pointer to the head of the stack
 * @line: Line number
 *
 * Description: If the stack contains less than two elements, prints an error
 * message and exits. If the top element of the stack is 0, prints an error
 * message and exits. Otherwise, computes the remainder of the division of the
 * second top element by the top element and
 * removes the top element from the stack.
 */
void mod_f(stack_t **head, unsigned int line)
{
	if (!*head || !(*head)->next)
	{
		free_stack(*head);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		free_stack(*head);
		fprintf(stdout, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	pop_f(head, line);
}
/**
 * pchar_f - Prints the ASCII character
 * represented by the top element of the stack
 * @head: Double pointer to the head of the stack
 * @line: Line number
 *
 * Description: If the stack is empty,
 * prints an error message and exits. If the
 * value of the top element is
 * not within the range of printable ASCII characters,
 * prints an error message and exits. Otherwise, prints the ASCII character
 * represented by the top element of the stack.
 */
void pchar_f(stack_t **head, unsigned int line)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (!((*head)->n > 64 && (*head)->n < 91) &&
			!((*head)->n > 96 && (*head)->n < 123))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*head)->n);
}
/**
 * pstr_f - Prints the string contained in the stack as ASCII characters.
 * @head: Pointer to a pointer to the head of the stack.
 * @line: Line number of the pstr command.
 */
void pstr_f(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	tmp = *head;
	(void)(line);
	while (tmp != NULL && tmp->n != 0 && isprint(tmp->n))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * rotr_f - Rotates the stack to the bottom,
 * moving the top element to the bottom.
 * @head: Pointer to a pointer to the head of the stack.
 * @line: Line number of the rotr command.
 */
void rotr_f(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	int lastV;
	(void)line;

	tmp = *head;
	if (*head && (*head)->next)
	{
		for (; tmp->next; tmp = tmp->next)
			;

		lastV = tmp->n;

		for (; tmp->prev; tmp = tmp->prev)
			tmp->n = tmp->prev->n;

		tmp->n = lastV;
	}
}
