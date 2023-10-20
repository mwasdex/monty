#include "monty.h"

/**
 * free_stack - free mem in doubly linked list.
 * @stack: doubly linked list representation of a stack.
 *
 * Return: nothing.
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (1)
	{
		temp = *stack;
		if ((*stack)->next == NULL)
		{
			free(temp);
			*stack = NULL;
			break;
		}
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * _mem - your main function is count the number of words
 * @buffr: string to validate.
 *
 * Return: number of words
 */

int _mem(char *buffr)
{
	int i, cnt = 2;
	char *delimit = " ";

	for (i = 0; buffr[i] != '\0'; i++)
	{
		if (buffr[i] == delimit[0])
			cnt++;
	}
	return (cnt);
}

/**
 * _pall - print the value in the node.
 * @stack: struct of the doubly linked list.
 * @line_number: number of the line in the file.
 *
 * Return: void.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - The opcode _pint prints the value at the top of the stack
 * @stack: struct of doubly linked list.
 * @line_number: line number currently in the file.
 *
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
