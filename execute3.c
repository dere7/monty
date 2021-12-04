#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: 0 if no error
 */
int pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->n < 0 && (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		return (EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
	return (EXIT_SUCCESS);
}

/**
 * pstr - prints the str at the top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: 0 if no error
 */
int pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *h = *stack;

	while (h == NULL || (h->n > 0 && h->n <= 127))
	{
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
