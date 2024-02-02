#include "monty.h"

/**
 * multiplay - Adds the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void multiplay(stack_t **stack_node, unsigned int line_number)
{
	int val;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		handleMoreErrors(8, line_number, "mul");

	(*stack_node) = (*stack_node)->next;
	val = (*stack_node)->n * (*stack_node)->prev->n;
	(*stack_node)->n = val;
	free((*stack_node)->prev);
	(*stack_node)->prev = NULL;
}

/**
 * modulas - Adds the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void modulas(stack_t **stack_node, unsigned int line_number)
{
	int val;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)

		handleMoreErrors(8, line_number, "mod");

	if ((*stack_node)->n == 0)
		handleMoreErrors(9, line_number);
	(*stack_node) = (*stack_node)->next;
	val = (*stack_node)->n % (*stack_node)->prev->n;
	(*stack_node)->n = val;
	free((*stack_node)->prev);
	(*stack_node)->prev = NULL;
}

