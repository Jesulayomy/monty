#ifndef MONTY_H_
#define MONTY_H_

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
 * struct xtrn_s - an externally declared variable
 * @value: linenumber
 * @m_script: the montyscript
 * @buffer: buffer holding the lines
 * @stack: the stack struct
 * @type: decides if to function as stack or queue
 */
typedef struct xtrn_s
{
	char *value;
	FILE *m_script;
	char *buffer;
	stack_t *stack;
	int type;
} xtrn_t;


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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif
