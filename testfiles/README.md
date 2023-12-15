# Some instructions on mu project:

The "checking.c" file contains several functions that perform different checks and validations. Here's a breakdown of each function:

"check_args_num" function:

It checks the number of arguments passed to the interpreter.
If the number of arguments is not what is expected (MIN_ARGS), it calls the "handle_error" function, passing an error code and other necessary parameters.
"check_access_rights" function:

It checks if the user has permissions to read the file specified by the "filename" parameter.
If the access is not granted, it prints an error message to the standard error stream and exits the program with a failure status.
"check_push_param" function:

It checks the parameter of the push instruction.
If the parameter is NULL or contains non-digit characters, it returns an error code (ERR_PUSH_USG). Otherwise, it returns a code indicating a valid parameter (VALID_PARM).
"check_digits" function:

It checks if all characters in a string are digits.
It iterates through the string and checks each character. If a non-digit character is encountered (except '-' for negative numbers), it returns 0. Otherwise, it returns 1 indicating that all characters are digits.
These functions are used for error checking and input validation within the program, ensuring that the program operates with valid data and handles errors appropriately.
