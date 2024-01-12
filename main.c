#include "monty.h"
int main(int argc, char *argv[])
{
	char *copy, *instruction, *token;
	int j;
	unsigned int line_number = 0, push_number;
	FILE *Monty = fopen(argv[1], "r");
	size_t len = 0;
	ssize_t i;
	char *line = NULL;
	stack_t *stack = NULL;
	stack_t *temp;

	instruction_t array_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL},
		{"nothing_here", NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	if (Monty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		i = getline(&line, &len, Monty);
		if (i != -1)
		{
			line_number = line_number + 1;
			copy = strdup(line);
			instruction = strtok(copy, "$ \n");
			if (instruction == NULL)
				continue;

			for (j = 0; strcmp(array_op[j].opcode, "nothing_here"); j++)
			{
				if (!strcmp(array_op[j].opcode, instruction))
				{
					if (!strcmp(array_op[j].opcode, "push"))
					{
						token = strtok(NULL, "$ \n");
						push_number = atoi(token);
						if (push_number == 0 && token[0] != '0')
						{
							array_op[j].f(NULL, line_number); /*case if push is incorrect */
							line = NULL;
							break;
						}
						else
						{
							if (stack == NULL)
							{
								temp = malloc(sizeof(stack_t));
								stack = temp;
								stack->n = 100;
							}

							array_op[j].f(&stack, push_number); /*case if push is correct */
							line = NULL;
							break;
						}
					}
					else if (!strcmp(array_op[j].opcode, "nop"))
					{
						line = NULL;
						break;
					}
					else
					{
						array_op[j].f(&stack, line_number);
						line = NULL;
						break;
					}
				}
			}
			if (!strcmp(array_op[j].opcode, "nothing_here"))
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
				exit(EXIT_FAILURE);
				line = NULL;
			}
		}
		else
			break;
	}

	fclose(Monty);
	return (0);
}
