#include "monty.h"

/**
 * _strdup - returns a pointer to newly allocated space in
 * memory, which contains a copy of given string
 * @str: string
 * Return: array of character
 */
char *_strdup(char *str)
{
	unsigned int i, size = strlen(str);
	char *ch;

	if (str == NULL)
		return (NULL);

	ch = malloc(sizeof(char) * size + 1);
	if (ch == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ch[i] = str[i];
	ch[i] = '\0';
	return (ch);
}

/**
 * add_node_end - add new node at the end of list
 * @head: head of list to be added
 * @n: string of node
 * Return: Pointer to newly created node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new, *h;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	h = *head;
	if (*head)
	{
		while ((*head)->next)
			*head = (*head)->next;
		(*head)->next = new;
		new->prev = *head;
		*head = h;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
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
