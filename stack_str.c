#include "monty.h"

/**
 * displayChar - Prints the Ascii value.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void displayChar(stack_t **stack_node, unsigned int line_number)
{
	int ascii_number;

	if (stack_node == NULL || *stack_node == NULL)
		handleStringErrors(11, line_number);

	ascii_number = (*stack_node)->n;
	if (ascii_number < 0 || ascii_number > 127)
		handleStringErrors(10, line_number);
	printf("%c\n", ascii_number);
}

/**
 * displayString - Prints a string.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void displayString(stack_t **stack_node, unsigned int line_number)
{
	(void)line_number;
	int ascii_number;
	stack_t *temp;

	if (stack_node == NULL || *stack_node == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack_node;
	while (temp != NULL)
	{
		ascii_number = temp->n;
		if (ascii_number <= 0 || ascii_number > 127)
			break;
		printf("%c", ascii_number);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotate - Rotates the first node of the stack_node to the bottom.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void rotate(stack_t **stack_node, unsigned int line_number)
{
	(void)line_number
		stack_t *temp;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		return;

	temp = *stack_node;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack_node;
	(*stack_node)->prev = temp;
	*stack_node = (*stack_node)->next;
	(*stack_node)->prev->next = NULL;
	(*stack_node)->prev = NULL;
}

/**
 * rotateReverse - Rotates the last node of the stack_node to the top.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void rotateReverse(stack_t **stack_node, unsigned int line_number)
{
	(void)line_number
		stack_t *temp;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		return;

	temp = *stack_node;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack_node;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack_node)->prev = temp;
	(*stack_node) = temp;
}

