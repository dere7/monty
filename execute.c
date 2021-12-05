#include "monty.h"

#define DELIM " \t\r\a\n"

int is_queue = 0;

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
	int status = 0;

	tok = strtok(line, DELIM);
	status = find_match(stack, tok, strtok(NULL, DELIM), line_number);
	free(line);
	return (status);
}

/**
 * push - pushes node
 * @stack: stack
 * @line_number: line number
 * @arg: number string
 * Return: returns 0 if no error
 */
int push(stack_t **stack, unsigned int line_number, char *arg)
{
	char *endPtr;

	strtol(arg == NULL ? "" : arg, &endPtr, 10);
	if (arg == NULL || *endPtr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	is_queue ? add_node_end(stack, atoi(arg)) : add_node(stack, atoi(arg));
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
