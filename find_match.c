#include "monty.h"

/**
 * find_match - findes match for opcode and execute it
 * @stack: stack
 * @opcode: opcode
 * @arg: arg
 * @line_number: line_number
 * Return: status code (0 if no error)
 */
int find_match(stack_t **stack, char *opcode, char *arg,
			   unsigned int line_number)
{
	static instruction_t instructions[] = {
			{"pall",  pall}, {"pint",  pint},
			{"pop",   pop}, {"swap",  swap},
			{"add",   add}, {"nop",   nop},
			{"sub",   sub}, {"div",   _div},
			{"mul",   mul}, {"mod",   mod},
			{"pchar", pchar}, {"pstr",  pstr},
			{"rotl",  rotl}, {"rotr",  rotr}, {NULL, NULL}};
	int i, status = 0;

	for (i = 0; opcode != NULL && instructions[i].opcode != NULL; i++)
	{
		if (opcode[0] == '#')
			break;
		else if (strcmp(opcode, "queue") == 0)
		{
			is_queue = 1;
			break;
		} else if (strcmp(opcode, "stack") == 0)
		{
			is_queue = 0;
			break;
		} else if (strcmp(opcode, "push") == 0)
		{
			status = push(stack, line_number, arg);
			break;
		} else if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			status = instructions[i].f(stack, line_number);
			break;
		}
	}
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		status = (EXIT_FAILURE);
	}
	return (status);
}
