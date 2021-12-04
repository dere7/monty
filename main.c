#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: argument length
 * @argv: arguments
 * Return: 0 if no error
 */
int main(int argc, char const *argv[])
{
	FILE *fp;
	char opcode[BUFSIZE];
	stack_t *stack = NULL;
	size_t lineNumber = 1;
	int status = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(opcode, BUFSIZE, fp) != NULL)
	{
		status = execute(opcode, &stack, lineNumber);
		if (status != 0)
			break;
		lineNumber++;
	}
	fclose(fp);
	free_stack(stack);
	return (status);
}


/**
 * sub - subtracts the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
	return (EXIT_SUCCESS);
}

/**
 * _div - divides the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}
	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
	return (EXIT_SUCCESS);
}

/**
 * mul - multiplies the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	product = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = product;
	return (EXIT_SUCCESS);
}

/**
 * mod - multiplies the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int mod(stack_t **stack, unsigned int line_number)
{
	int modulus;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return (EXIT_FAILURE);
	}
	modulus = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = modulus;
	return (EXIT_SUCCESS);
}
