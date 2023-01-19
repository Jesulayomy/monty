#include "monty.h"

xtrn_t mt;

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

void (*get_op(char *opcode, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t op_code[] = {
		{"pall", _pall},
		//{"add", _add},
	//	{"swap", _swap},
	//	{"pop", _pop},
	//	{"push", _push},
		{NULL, NULL},
	};
	int i, boolean;

	for (i = 0; op_code[i].opcode; i++)
	{
		boolean = strcmp(opcode, op_code[i].opcode);
		if (boolean == 0)
			return (op_code[i].f);
	}

	fprintf(stderr, "L%d unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - runs the monty script in a noninteractive mode
 * @argv: the arg vector
 * @argc: argument count
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	unsigned int line_no;
	char *line;
	char *cmd;
	void (*func)(stack_t **stack, unsigned int line_no);

	mt.stack = NULL;
	mt.buffer = NULL;
	mt.value = NULL;
	mt.type = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	mt.m_script = fopen(argv[1], "r");
	if (mt.m_script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_no = 0;
	while (1)
	{
		line_no++;

		mt.buffer = malloc(sizeof(char) * 1024);
		if (mt.buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		line = fgets(mt.buffer, 1024, mt.m_script);
		if (line == NULL)
			break;

		cmd = strtok(mt.buffer, " \n\t\a\r");
		mt.value = strtok(NULL, " \n\t\a\r");
		if (cmd != NULL && cmd[0] != 35)
		{
			// run the command by calling the func
			func = get_op(cmd, line_no);
			func(&mt.stack, line_no);
		}
		free(mt.buffer);
	}

	return (0);
}
