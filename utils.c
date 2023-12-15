#include "monty.h"

/**
  * check_args_num - Check the arguments passed on to the interpreter
  * @argn: Number of args
  *
  * Return: Nothing
  */
void check_args_num(int argn)
{
	if (argn != 2)
		handle_error(200, NULL, 0, NULL);
}

/**
  * check_access_rights - CChecks if the user has permissions to read the file
  * @filename: The pathname of the file
  *
  * Return: Nothing
  */
void check_access_rights(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
  * open_file - Opens a file to interpret the commands within
  * @filename: The file to be opened
  *
  * Return: The file descriptor of the opened file
  */
FILE *open_file(char *filename)
{
	FILE *fd = NULL;

	check_access_rights(filename);

	fd = fopen(filename, "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
  * handle_execution - Manages the operations to be executed by the interpreter
  * @op_code: The operation code to manage
  * @op_param: The parameter of the instruction
  * @line: The line on which the error occurred
  * @m: The method to be used by the interpreter
  *
  * Return: 0 if the operation was executed correctly or errcode if is invalid
  */
int handle_execution(char *op_code, char *op_param, unsigned int line, int m)
{
	int status_op = 0;
	void (*oprt)(stack_t **, unsigned int);

	if (strcmp(op_code, "stack") == 0)
		return (300);
	else if (strcmp(op_code, "queue") == 0)
		return (301);

	oprt = pick_func(op_code);
	if (oprt)
	{
		if (strcmp(op_code, "push") == 0)
		{
			status_op = check_push_param(op_param);
			if (status_op == 201)
				return (201);

			if (m != 0 && m == 301)
				oprt = pick_func("push_queue");

			oprt(&head, atoi(op_param));
		}
		else
		{
			oprt(&head, line);
		}

		return (m);
	}

	return (100);
}
