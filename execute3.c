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
	if ((*stack)->n < 0 || (*stack)->n > 127)
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

	while (h != NULL && (h->n > 0 && h->n <= 127))
	{
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 * Return: 0 if no error
 */
int rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack, *h;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	for (h = *stack; h->next != NULL; h = h->next)
		;
	h->next = temp;
	return (EXIT_SUCCESS);
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: 0 if no error
 */
int rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *h;

	for (h = *stack; h->next != NULL; h = h->next)
		;
	h->prev->next = NULL;
	h->next = *stack;
	*stack = h;
	return (EXIT_SUCCESS);
}
