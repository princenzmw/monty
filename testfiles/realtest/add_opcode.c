#include "monty.h"

#include "monty.h"

/**
  * count_stack - Counts the number of elements in the stack
  * @stack: The stack to count
  *
  * Return: Number of elements in the stack
  */
unsigned int count_stack(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int lenght = 0;

	while (current != NULL)
	{
		++lenght;
		current = current->next;
	}

	return (lenght);
}

/**
 * add - Adds the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(205, NULL, line_number, NULL);

	a = temp->n;
	b = temp->next->n;
	temp->next->n = a + b;
	*stack = temp->next;
	free(temp);
}
