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
			{"push", push_node},
			{"pall", print_stack},
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
		return (EXIT_FAILURE);
	}
	free(line);
	return (status);
}

/**
 * push_node - pushes node
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int push_node(stack_t **stack, unsigned int line_number)
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
 * print_stack - prints stack
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int print_stack(stack_t **stack,
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
 * add_node - add new node at the begginning of list
 * @head: head of list to be added
 * @n: int to be added
 * Return: Pointer to newly created node
 */
stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * free_dlistint - frees list
 * @head: head of list
 */
void free_dlistint(stack_t *head)
{
	stack_t *h;

	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
