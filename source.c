#include "monty.h"

/**
 * main - runs the monty script in a noninteractive mode
 * @argv: the arg vector
 * @argc: argument count
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	FILE *m_script;
	int line_no;
	char *line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_script = fopen(argv[1], "r");
	if (script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_no = 0;
	while(1)
	{
		fgets(line, 1024, m_script);
		line_no++;
		if (line == NULL)
			break;
	}

	return (0);
}
