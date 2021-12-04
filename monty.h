#ifndef MONTY_H
#define MONTY_H
#define BUFSIZE 120
#include <stddef.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern char *arg;
extern stack_t *stack;
stack_t *add_node(stack_t **head, int n);
int execute(char *str, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
/* opcodes */
int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_number);
int pop(stack_t **stack, unsigned int line_number);
int swap(stack_t **stack, unsigned int line_number);
int add(stack_t **stack, unsigned int line_number);
int sub(stack_t **stack, unsigned int line_number);
int mul(stack_t **stack, unsigned int line_number);
int _div(stack_t **stack, unsigned int line_number);
int mod(stack_t **stack, unsigned int line_number);
int nop(stack_t **stack, unsigned int line_number);
int pchar(stack_t **stack, unsigned int line_number);
int pstr(stack_t **stack, unsigned int line_number);
int rotl(stack_t **stack, unsigned int line_number);
int rotr(stack_t **stack, unsigned int line_number);

/* string utilities */
char *_strdup(char *str);
#endif
