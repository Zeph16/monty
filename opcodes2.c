#include "monty.h"

/**
 * pall - prints all values from the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp)
	{
		if (temp->n != 0 && isascii(temp->n))
			putchar(temp->n);
		else
			break;

		temp = temp->next;
	}

	putchar('\n');
}


/**
 * rotl - rotates the stack to the top
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	temp = *stack;

	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = temp;

	*stack = top;

	(void) line_number;
}
