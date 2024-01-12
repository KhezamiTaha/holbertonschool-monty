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
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		newNode->n = line_number;
		newNode->prev = NULL;
		if ((*stack)->n == 100)
			newNode->next = NULL;
		else
			newNode->next = *stack;
		*stack = newNode;
	}
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	
	stack_t *temp;
	if (!isEmpty(stack))
	{
		temp = *stack;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (isEmpty(stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (isEmpty(stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if(*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next->prev = temp;

}

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if(*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
int isEmpty(stack_t **stack)
{
	if (*stack == NULL)
		return (1);
	else
		return (0);
}
