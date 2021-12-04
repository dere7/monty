#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "monty.h"
/**
 * swap_nodes - swaps the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int swap_nodes(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
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
