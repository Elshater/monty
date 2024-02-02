#include "monty.h"

/**
 * nopFunc - Does nothing.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void nopFunc(stack_t **stack_node, unsigned int line_number)
{
	(void)stack_node;
	(void)line_number;
}

/**
 * swapNodes - Swaps the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void swapNodes(stack_t **stack_node, unsigned int line_number)
{
	stack_t *temp;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		handleMoreErrors(8, line_number, "swap");
	temp = (*stack_node)->next;
	(*stack_node)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack_node;
	temp->next = *stack_node;
	(*stack_node)->prev = temp;
	temp->prev = NULL;
	*stack_node = temp;
}

/**
 * add - Adds the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void add(stack_t **stack_node, unsigned int line_number)
{
	int val;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		handleMoreErrors(8, line_number, "add");

	(*stack_node) = (*stack_node)->next;
	val = (*stack_node)->n + (*stack_node)->prev->n;
	(*stack_node)->n = val;
	free((*stack_node)->prev);
	(*stack_node)->prev = NULL;
}

/**
 * subtract - Adds the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void subtract(stack_t **stack_node, unsigned int line_number)
{
	int val;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)

		handleMoreErrors(8, line_number, "sub");

	(*stack_node) = (*stack_node)->next;
	val = (*stack_node)->n - (*stack_node)->prev->n;
	(*stack_node)->n = val;
	free((*stack_node)->prev);
	(*stack_node)->prev = NULL;
}

/**
 * devide - Adds the top two elements of the stack_node.
 * @stack_node: Pointer to a pointer pointing to top node of the stack_node.
 * @line_number: Interger representing the line number of of the code.
 */
void devide(stack_t **stack_node, unsigned int line_number)
{
	int val;

	if (stack_node == NULL || *stack_node == NULL || (*stack_node)->next == NULL)
		handleMoreErrors(8, line_number, "div");

	if ((*stack_node)->n == 0)
		handleMoreErrors(9, line_number);
	(*stack_node) = (*stack_node)->next;
	val = (*stack_node)->n / (*stack_node)->prev->n;
	(*stack_node)->n = val;
	free((*stack_node)->prev);
	(*stack_node)->prev = NULL;
}

