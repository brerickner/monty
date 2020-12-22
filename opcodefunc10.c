#include "monty.h"
/**
 * push - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that adds node to stack
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *addNode;
	(void)line_number;

	/* printf("got to push\n"); */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->prev = NULL;
	if (!exttokens.numFind)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = exttokens.numFind;

	addNode = new_node;
	if (!addNode || !stack)
		return;
	addNode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = addNode;
	*stack = addNode;
}
/*
* newnode = malloc(sizeof(stack_t));
*
*	if (newnode == NULL)
*		 printf("malloc failed in push\n");
*		return;
*
*	lastnode = (*stack);
*
*	newnode->next = NULL;
*	newnode->n = exttokens.numFind;
*
*	if ((*stack) == NULL)
*	{
*
*		newnode->prev = NULL;
*		(*stack) = newnode;
*		 printf("stack is NULL in push\n");
*
*	}
*
*
*	else
*	{
*		printf("meow\n");
*		while (lastnode->next != NULL)
*			lastnode = lastnode->next;
*
*		lastnode->next = newnode;
*		newnode->prev = lastnode;
*		printf("lastnode: %i newnode: %i \n", lastnode->n, newnode->n);
*	}
*	printf("top of stack = %i \n", (*stack)->n);
* }
*/


/**
 * pall - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that prints all numbers on stack
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
/*
 *	if (*(stack) == NULL)
 *	{
 *		fprintf(stderr, "Error: malloc failed\n");
 *		exit(EXIT_FAILURE);
 *		}
 */
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that prints number at top of stack
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * nop - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that does nothing
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	/* printf("testing nop func \n "); */
}
