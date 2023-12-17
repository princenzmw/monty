#include "monty.h"

/**
 * sub - Subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(206, NULL, line_number, NULL);

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b - a;
	*stack = temp->next;
	free(temp);
}

/**
 * divide - Divides the second top element by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(207, NULL, line_number, NULL);

	a = temp->n;

	if (a == 0)
		handle_error(208, NULL, line_number, NULL);

	b = temp->next->n;
	temp->next->n = b / a;
	*stack = temp->next;
	free(temp);
}

/**
 * mul - Multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(209, NULL, line_number, NULL);

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b * a;
	*stack = temp->next;
	free(temp);
}

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(210, NULL, line_number, NULL);

	a = temp->n;

	if (a == 0)
		handle_error(208, NULL, line_number, NULL);

	b = temp->next->n;
	temp->next->n = b % a;
	*stack = temp->next;
	free(temp);
}
