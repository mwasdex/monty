#include "monty.h"

/**
 * _add - The opcode add adds the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line number in the file.
 *
 * Return: nothing.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	val += (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = val;
}

/**
 * _mop - The opcode nop doesn’t do anything.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line_number in the file.
 *
 * Return: nothing.
 */

void _mop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _sub - The opcode sub, substraction the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line number in the file.
 *
 * Return: nothing.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	val -= (*stack)->next->n;
	val *= -1;
	_pop(stack, line_number);
	(*stack)->n = val;
}
