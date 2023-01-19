#include "monty.h"

/**
 * _push - prints all the elements of the stack
 * @stack: the stack as a doubly linked list
 * @line_no: to return in case of an error
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_no)
{
	stack_t *new, *temp = *stack;
	int n;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_xtrn();
		exit(EXIT_FAILURE);
	}

	if (my_isdigit(mt.value) == 1)
		n = atoi(mt.value);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		free_xtrn();
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (!(*stack))
		*stack = new;
	else
	{
		for (; temp->next; temp = temp->next)
			;
		new->prev = temp;
		temp->next = new;
	}
}

/**
 * _pall - prints all the elements of the stack
 * @stack: the stack as a doubly linked list
 * @line_no: to return in case of an error
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	(void)line_no;

	if (temp != NULL)
	{
		for (; temp->next; temp = temp->next)
			;
		for (; temp; temp = temp->prev)
			printf("%d\n", temp->n);
	}
}
