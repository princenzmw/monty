#include "monty.h"

/**
  * add_node_beginning - Adds a new node at the beginning of the stack
  * @head: The head of the stack
  * @value: The value to adds on the stack
  *
  * Return: Nothing
  */
void add_node_beginning(stack_t **head, unsigned int value)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = value;
	if (*head)
	{
		new_node->next = *head;
		new_node->prev = (*head)->prev;
		(*head)->prev = new_node;
		*head = new_node;
		return;
	}

	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
  * add_node_end - Adds a new node at the end of the stack
  * @head: The head of the stack
  * @value: The value to adds on the stack
  *
  * Return: Nothing
  */
void add_node_end(stack_t **head, unsigned int value)
{
	stack_t *current = NULL, *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = value;
	if (*head)
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;

		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
		return;
	}

	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
