#include "monty.h"


/**
 * free_xtrn - frees the xtrn struct
 * Return: nothing
 */
void free_xtrn(void)
{
	fclose(mt.m_script);
	free(mt.buffer);
	free_stack(mt.stack);
}


/**
 * free_stack - frees the xtrn stack
 * @head: the stack to free
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current_node = NULL;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}


/**
 * my_isdigit - check if a string contains digits only
 * @nstr: string to be checked
 * Return: 1 if digit, 0 if not digit
 */
int my_isdigit(char *nstr)
{
	int i;

	if (nstr == NULL)
		return (0);
	for (i = 0; nstr[i] != '\0' ; i++)
	{
		if (nstr[i] < 48 || nstr[i] > 57)
			return (0);
	}

	return (1);
}
