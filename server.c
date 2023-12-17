#include "monty.h"

/**
  * check_digits - Checks if all characters in a string are digits
  * @s: The string to be evaluated
  *
  * Return: 1 if all if all evaluated characters are digits or 0 if not
  */
int check_digits(char *s)
{
	int status = 1;

	while (*s != '\0')
	{
		if (s[0] == 45)
		{
			++s;
			continue;
		}

		if (isdigit(*s) == 0)
		{
			status = 0;
			return (status);
		}

		++s;
	}

	return (status);
}

/**
  * pick_func - Select the function that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function don't exists
  */
void (*pick_func(char *s))(stack_t **, unsigned int)
{
	instruction_t insts[] = {
		{ "push", push },
		{ "push_queue", push_queue },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "div", divide },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i = 0;

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
			return (insts[i].f);

		++i;
	}

	return (NULL);
}

/**
  * check_push_param - Check the parameter of the push instruction
  * @param: The parameter to be verified
  *
  * Return: 0 if is a valid param or errcode if is invalid
  */
int check_push_param(char *param)
{
	if (param == NULL || check_digits(param) == 0)
		return (201);

	return (0);
}
