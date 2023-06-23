#include "monty.h"

void execute_fun(buf_struct *bf)
{
    stack_t *stack = NULL;
	int line_number = 1, i = 0;

	while (bf->list_cmd[i])
	{
		split_line(bf->list_cmd[i], bf);
		if (strcmp(bf->tok_cmd[0], "push") == 0)
		{
			if(!bf->tok_cmd[1] || digits_only(bf->tok_cmd[1]) == 0)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, atoi(bf->tok_cmd[1]));
		}
		else
		{
			if (get_op_func(bf->tok_cmd[0]) == NULL)
			{
				free_stack(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, bf->tok_cmd[0]);
				exit(EXIT_FAILURE);
			}
			(*get_op_func(bf->tok_cmd[0]))(&stack, line_number);
		}
		line_number++;
		i++;
	}
	free_stack(stack);
}

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
    instruction_t opf[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/* {"nop", nop},*/
		/* {"swap", swap},*/
		/* {"add", add},*/
		{NULL, NULL}
	};

    int i = 0;

	while (opf[i].opcode)
	{
		if (strcmp(s, opf[i].opcode) == 0)
		{
			return (opf[i].f);
		}
		i++;
	}
	return (opf[i].f);
}
