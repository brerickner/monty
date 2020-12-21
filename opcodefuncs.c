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
	stack_t *newnode;
	stack_t *lastnode;
	(void)line_number;

	printf("got to push\n");

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		/* printf("malloc failed in push\n"); */
		return;

	lastnode = (*stack);

	newnode->next = NULL;
	newnode->n = exttokens.numFind;

	if ((*stack) == NULL)
	{
		newnode->prev = NULL;
		(*stack) = newnode;
		/* printf("stack is NULL in push\n"); */
		return;
	}

	while (lastnode->next != NULL)
		lastnode = lastnode->next;

	lastnode->next = newnode;
	newnode->prev = lastnode;
}



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

	/* printf("got to pall"); */
	if (*(stack) == NULL)
		return;

	for (temp = (*stack)->next; temp != NULL; temp = temp->next)
		;
	for (temp = (*stack); temp != NULL; temp = temp->prev)
		printf("%d", temp->n);
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
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
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
