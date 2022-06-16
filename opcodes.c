#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->prev = temp;
	(*stack)->next = temp->next;

	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *stack;

	temp->next = *stack;

	*stack = temp;
}


/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	product = temp->next->n % temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}


/**
 * nop - doesn’t do anything :)
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}


/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!stack || !(*stack))
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	if (!isascii(num))
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}


/**
 * rotr - rotates the stack to the bottom
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*stack)->prev = temp;

	(*stack) = temp;

	(void) line_number;
}
