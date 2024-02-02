#include "monty.h"

/**
 * handleError - Prints error messages  by their error code.
 * @code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void handleError(int code, ...)
{
	va_list arg_ptr;
	char *operation;
	int lineNumber;

	va_start(arg_ptr, code);
	switch (code)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg_ptr, char *));
		break;
	case 3:
		lineNumber = va_arg(arg_ptr, int);
		operation = va_arg(arg_ptr, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, operation);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg_ptr, int));
		break;
	default:
		break;
	}
	nodeFree();
	exit(EXIT_FAILURE);
}

/**
 * handleMoreErrors - handles errors.
 * @code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void handleMoreErrors(int code, ...)
{
	va_list arg_ptr;
	char *operation;
	int lineNumber;

	va_start(arg_ptr, code);
	switch (code)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg_ptr, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg_ptr, int));
		break;
	case 8:
		lineNumber = va_arg(arg_ptr, unsigned int);
		operation = va_arg(arg_ptr, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, operation);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg_ptr, unsigned int));
		break;
	default:
		break;
	}
	nodeFree();
	exit(EXIT_FAILURE);
}

/**
 * handleStringErrors - handles errors.
 * @code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void handleStringErrors(int code, ...)
{
	va_list arg_ptr;
	int lineNumber;

	va_start(arg_ptr, code);
	lineNumber = va_arg(arg_ptr, int);
	switch (code)
	{
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		break;
	default:
		break;
	}
	nodeFree();
	exit(EXIT_FAILURE);
}

