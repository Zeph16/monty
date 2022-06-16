#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}

/**
 * push - pushes new node to the end of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;

	num = strtok(NULL, DELIMS);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(num);
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;

	*stack = node;
}
