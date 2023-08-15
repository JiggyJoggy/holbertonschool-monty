#include "monty.h"

/**
 * push - pushes a new node onto the top of the stack
 *
 * @stack: pointer to pointer to top of stack
 *
 * @line_number: line num of read line
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *token;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t\n");

	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);

	if (strspn(token, "0123456789+-") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pop - removes the top element of stack
 *
 * @stack: pointer to pointer to top of the stack
 *
 * @line_number: line num of read line
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
