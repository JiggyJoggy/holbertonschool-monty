#include "monty.h"

/**
 * free_s - entry point
 *
 * description: frees stack_t
 *
 * @stack: stack
 */

void free_s(stack_t *stack)
{
	stack_t *next_stack;

	while (stack != NULL)
	{
		next_stack = stack->next;
		free(stack);
		stack = next_stack;
	}
}
