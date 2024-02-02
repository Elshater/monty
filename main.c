#include "monty.h"
stack_t *headNode = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	nodeFree();
	return (0);
}

/**
 * create - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handleError(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * nodeFree - Frees nodes in the stack.
 */
void nodeFree(void)
{
	stack_t *temp;

	if (headNode == NULL)
		return;

	while (headNode != NULL)
	{
		temp = headNode;
		headNode = headNode->next;
		free(temp);
	}
}

/**
 * insertToQueue - Adds a node to the queue.
 * @new: Pointer to the new node.
 * @line: line number of the code.
 */
void insertToQueue(stack_t **new, __attribute__((unused)) unsigned int line)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new;
	(*new)->prev = temp;
}

