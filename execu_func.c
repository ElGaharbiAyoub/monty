#include "monty.h"
/**
 * execute_fun - Executes the commands stored in bf->list_cmd.
 * @bf: Pointer to the buf_struct object.
 */
void execute_fun(buf_struct *bf)
{
	stack_t *stack = NULL;
	int line_n = 1, i = 0;
	void (*op_func)(stack_t **stack, unsigned int line_number) = NULL;

	while (bf->list_cmd[i])
	{
		if (is_empty_line(bf->list_cmd[i]) == 1)
		{
			line_n++;
			i++;
			continue;
		}
		split_line(bf->list_cmd[i], bf);
		if (strcmp(bf->tok_cmd[0], "push") == 0)
		{
			if (!bf->tok_cmd[1] || digits_only(bf->tok_cmd[1]) == 0)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, atoi(bf->tok_cmd[1]));
		}
		else
		{
			op_func = get_op_func(bf->tok_cmd[0]);
			if (op_func == NULL)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_n, bf->tok_cmd[0]);
				exit(EXIT_FAILURE);
			}
			(*get_op_func(bf->tok_cmd[0]))(&stack, line_n);
		}
		line_n++;
		i++;
	}
	free_stack(stack);
}

/**
 * get_op_func - Retrieves the corresponding function pointer
 *  based on the opcode.
 * @s: The opcode string.
 *a
 * Return: Pointer to the corresponding function, or NULL if opcode not found.
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opf[] = {
		{"pop", pop_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"swap", swap_f},
		{"add", add_f},
		{"nop", nop_f},
		{"sub", sub_f},
		{"div", div_f},
		{"mul", mul_f},
		{"mod", mod_f},
		{"pchar_f", pchar_f},
		{NULL, NULL}
	};

	int i = 0;

	while (opf[i].opcode)
	{
		if (strncmp(s, opf[i].opcode, (strlen(s))) == 0)
		{
			return (opf[i].f);
		}
		i++;
	}
	return (NULL);
}
