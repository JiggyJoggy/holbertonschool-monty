#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - entry point
 *
 * description: doubly linked lists of a stack
 * @n: int
 * @prev: points to previous element of stack
 * @next: points to next element of stack
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct operate_s - entry point
 *
 * description: opcode and functions
 * @opcode: opcode
 * @func: function to handle the opcode
 */

typedef struct operate_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
} operate_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute((unused))unsigned int line_number);
#endif
