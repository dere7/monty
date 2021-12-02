#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
stack_t *stack;
int main(int argc, char const *argv[])
{
	FILE *fp;
	char opcode[BUFSIZE];
	size_t lineNumber = 1;

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
		if (execute(opcode, &stack, lineNumber) != 0)
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n", lineNumber, opcode);
			fclose(fp);
			free_dlistint(stack);
			exit(EXIT_FAILURE);
		}
		lineNumber++;
	}
	fclose(fp);
	return (EXIT_SUCCESS);
}
