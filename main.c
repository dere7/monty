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
	free_dlistint(stack);
	return (status);
}
