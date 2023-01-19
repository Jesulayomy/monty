#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: stack
 * @line_no: line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_xtrn();
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n + temp->next->n);

	_pop(stack, line_no);
	_pop(stack, line_no);

	mt.value = num;
	prev_is_stack = mt.type;
	mt.type = 1;
	_push(stack, line_no);
	mt.type = prev_is_stack;

	free(num);
}

