#include "monty.h"

/**
 * find_op - entry point
 *
 * description: finds matching opcode for function
 *
 * @stack: points to pointer of stack
 * @line_number: line num of read line
 */

void find_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	int index = 0;
	operate_s operate[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (operate[index].opcode != NULL)
	{
		if (strcmp(opcode, operate[index].opcode) == 0)
		{
			operate[index].f(stack, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%u: unknown operate %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
