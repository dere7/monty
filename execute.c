#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

#define DELIM " \t\r\a\n"
char *arg;

/**
 * execute - executes opcode
 * @str: opcode
 * @stack: stack
 * @line_number: line number
 * Return: 0 if success other int if error occurs
 */
int execute(char *str, stack_t **stack, unsigned int line_number)
{
	char *tok, *line = _strdup(str);
	int i, status = 0;
	static instruction_t instructions[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop",  pop},
			{"swap", swap},
			{"add",  add},
			{"nop",  nop},
			{"sub",  sub},
			{"div",  _div},
			{"mul",  mul},
			{"mod",  mod},
			{NULL, NULL}
	};

	tok = strtok(line, DELIM);
	for (i = 0; tok != NULL && instructions[i].opcode != NULL; i++)
		if (strcmp(tok, instructions[i].opcode) == 0)
		{
			tok = strtok(NULL, DELIM);
			arg = tok;
			status = instructions[i].f(stack, line_number);
			break;
		}
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tok);
		status = (EXIT_FAILURE);
	}
	free(line);
	return (status);
}

/**
 * push - pushes node
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int push(stack_t **stack, unsigned int line_number)
{
	char *endPtr;

	strtol(arg == NULL ? "" : arg, &endPtr, 10);
	if (arg == NULL || *endPtr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	add_node(stack, atoi(arg));
	return (EXIT_SUCCESS);
}

/**
 * pall - prints stack
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int pall(stack_t **stack,
		 __attribute__((unused)) unsigned int line_number)
{
	stack_t *h;

	if (stack == NULL && *stack == NULL)
		return (EXIT_SUCCESS);
	for (h = *stack; h != NULL; h = h->next)
		printf("%d\n", h->n);
	return (EXIT_SUCCESS);
}

/**
 * pint - prints value at the top stack
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	return (EXIT_SUCCESS);
}

/**
 * pop - removes value at the top stack
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}
	h = (*stack)->next;
	free(*stack);
	if (h != NULL)
		h->prev = NULL;
	*stack = h;
	return (EXIT_SUCCESS);
}
