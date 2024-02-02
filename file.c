#include "monty.h"

/**
 * open_f - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_f(char *nameFile)
{
	FILE *fd = fopen(nameFile, "r");

	if (nameFile == NULL || fd == NULL)
		handleError(2, nameFile);

	readf(fd);
	fclose(fd);
}

/**
 * readf - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readf(FILE *fd)
{
	int line_number, form = 0;
	char *buff = NULL;
	size_t lenth = 0;

	for (line_number = 1; getline(&buff, &lenth, fd) != -1; line_number++)
	{
		form = parse(buff, line_number, form);
	}
	free(buff);
}

/**
 * parse - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_number: line number
 * @form:  storage form. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the code is stack. 1 if queue.
 */

int parse(char *buff, int line_number, int form)
{
	char *code, *val;
	const char *delimiter = "\n ";

	if (buff == NULL)
		handleError(4);

	code = strtok(buff, delimiter);
	if (code == NULL)
		return (form);
	val = strtok(NULL, delimiter);

	if (strcmp(code, "stack") == 0)
		return (0);
	if (strcmp(code, "queue") == 0)
		return (1);

	get_func(code, val, line_number, form);
	return (form);
}

/**
 * get_func - find the appropriate function for the code
 * @code: code
 * @val: argument of code
 * @form:  storage form. If 0 Nodes will be entered as a stack.
 * @line: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void get_func(char *code, char *val, int line, int form)
{
	int i;
	int f;

	instruction_t func_list[] = {
		{"push", insertToStack},
		{"pall", displayStack},
		{"pint", displayTop},
		{"pop", deleteTop},
		{"nopFunc", nopFunc},
		{"swap", swapNodes},
		{"add", add},
		{"sub", subtract},
		{"div", devide},
		{"mul", multiplay},
		{"mod", modulas},
		{"pchar", displayChar},
		{"pstr", displayString},
		{"rotl", rotate},
		{"rotr", rotateReverse},
		{NULL, NULL}};

	if (code[0] == '#')
		return;

	for (f = 1, i = 0; func_list[i].code != NULL; i++)
	{
		if (strcmp(code, func_list[i].code) == 0)
		{
			invoke_function(func_list[i].f, code, val, line, form);
			f = 0;
		}
	}
	if (f == 1)
		handleError(3, line, code);
}

/**
 * invoke_function - Calls the required function.
 * @function: Pointer to the function that is about to be called.
 * @operation: string representing the code.
 * @val: string representing a numeric value.
 * @line: line numeber for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void invoke_function(op_func func, char *operation, char *val, int line, int form)
{
	stack_t *n;
	int f;
	int i;

	f = 1;
	if (strcmp(operation, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			handleError(5, line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handleError(5, line);
		}
		n = create(atoi(val) * f);
		if (form == 0)
			func(&n, line);
		if (form == 1)
			insertToQueue(&n, line);
	}
	else
		func(&headNode, line);
}

