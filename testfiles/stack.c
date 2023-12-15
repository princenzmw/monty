#include "monty.h"
stack_t *stack = NULL;
int error_code = 0;
int main(int argc, char **argv)
{
	check_args_num(argc);
	check_access_rights(argv[1]);
	process_file(argv[1]);
	return (0);
}
