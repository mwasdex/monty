#include "monty.h"

/**
 * _pop - The opcode pop removes the top element of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: Currently line number in the file.
 *
 * Return: nothing.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
	{
		free(temp);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * _push - The opcode push pushes an element to the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: currently line number in the file.
 *
 * Return: nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	unsigned int num, i;

	for (i = 0; i < strlen(number); i++)
	{
		if (number[i] == '-')
			i++;
		if (!isdigit(number[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(number);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = num;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _swap - The opcode swaps the top two elements of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: currently line number in the file
 *
 * Return: the new node at the beginning
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->next->prev = *stack;
	*stack = temp;
}
