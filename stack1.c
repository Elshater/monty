#include "monty.h"

/**
 * insertToStack - Adds a node to the stack.
 * @new: Pointer to the new node.
 * @line: Interger representing the line number of of the code.
 */
void insertToStack(stack_t **new, __attribute__((unused)) unsigned int line)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (headNode == NULL)
	{
		headNode = *new;
		return;
	}
	temp = headNode;
	headNode = *new;
	headNode->next = temp;
	temp->prev = headNode;
}

/**
 * displayStack - Adds a node to the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: line number of  the code.
 */
void displayStack(stack_t **stack_node, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack_node == NULL)
		exit(EXIT_FAILURE);
	temp = *stack_node;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * deleteTop - Adds a node to the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void deleteTop(stack_t **stack_node, unsigned int line_number)
{
	stack_t *temp;

	if (stack_node == NULL || *stack_node == NULL)
		handleMoreErrors(7, line_number);

	temp = *stack_node;
	*stack_node = temp->next;
	if (*stack_node != NULL)
		(*stack_node)->prev = NULL;
	free(temp);
}

/**
 * displayTop - Prints the top node of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void displayTop(stack_t **stack_node, unsigned int line_number)
{
	if (stack_node == NULL || *stack_node == NULL)
		handleMoreErrors(6, line_number);
	printf("%d\n", (*stack_node)->n);
}

