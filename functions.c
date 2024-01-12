#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		newNode = malloc(sizeof(stack_t));
		if (newNode == NULL)
		{
			fprintf(stderr, "Stack Overflow");
			exit(EXIT_FAILURE);
		}
		newNode->n = line_number;
		newNode->prev = NULL;
		newNode->next = *stack;
		*stack = newNode;
	}
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

	stack_t *temp;
	temp = *stack;
	if (isEmpty(stack))
	{
		fprintf(stderr, "Stack Underflow");
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

int isEmpty(stack_t **stack)
{
	if (stack == NULL)
		return (1);
	else
		return (0);
}
