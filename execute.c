#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "monty.h"
#define DELIM " \t\r\n\a"

stack_t *stack;
int execute(char *str, size_t lineNumber)
{
	char *tok, *line = strdup(str);

	tok = strtok(line, DELIM);
	if (tok != NULL)
	{
		if (strcmp(tok, "push") == 0)
		{
			tok = strtok(NULL, DELIM);
			if (tok != NULL)
				add_node(&stack, atoi(tok));
			else
				return -1;
		}
		else if (strcmp(tok, "pall") == 0)
		{
			tok = strtok(NULL, "\n");
			if (tok != NULL && !isspace(tok[0]))
				printf("%s\n", tok);
			else
				print_dlistint(stack, lineNumber);
		}
	}

	return (0);
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
 * print_dlistint - prints doubly linked list
 * @h: head of the list
 * Return: number of nodes
 */
size_t print_dlistint(stack_t *h, unsigned int line_number)
{
	size_t i = line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}

	return (i);
}
