#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	char opcode[BUFSIZE];
	size_t lineNumber = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(opcode, BUFSIZE, fp) != NULL)
	{
		if (execute(opcode, lineNumber) != 0){
			dprintf(STDERR_FILENO, "L%ld: unknown instruction %s", lineNumber, opcode);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		lineNumber++;
	}
	fclose(fp);
	return (EXIT_SUCCESS);
}
