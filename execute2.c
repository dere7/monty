#include "monty.h"
/**
 * swap - swaps the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int swap(stack_t **stack, unsigned int line_number)
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
 * add - adds the top two elements
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
	return (EXIT_SUCCESS);
}
/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number
 * Return: returns 0 if no error
 */
int nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	return (EXIT_SUCCESS);
}

/**
 * add_node - add new node at the beginning of list
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
 * free_stack - frees stack
 * @head: head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *h;

	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
