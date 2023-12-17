#include "monty.h"

/**
  * handle_cerror - Manages common interpreter errors
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_cerror(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case 100:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case 101:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * handle_more_uerror - Manages interpreter usage errors
  * @errno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_more_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case 211:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case 212:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}

/**
  * handle_uerror - Manages interpreter usage errors
  * @errno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case 200:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 201:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case 202:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case 203:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case 204:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case 205:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case 206:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case 207:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case 208:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case 209:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case 210:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
  * frees_stack - Releases all elements in the stack
  *
  * Return: Nothing
  */
void frees_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}

/**
  * handle_error - Manages the printing of interpreter errors
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  * @buff: The reserved error line buffer
  *
  * Return: Nothing
  */
void handle_error(int errno, char *opcode, unsigned int line, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_uerror(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_more_uerror(errno, line);
	else
		return;

	frees_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}
