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
	stack_t newNode, temp;

	newNode = malloc(sizeof(stack_t));
/*malloc check*/
	if (newNode == NULL)
		exit(EXIT_FAILURE);
/*if no number for argument*/
	if (exttokens.numFind == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
/*store list in temp node*/
	temp = (*stack)->next;
/*add newNode to stack*/
	newNode->prev = *stack;
	newNode->next = temp;
	if (temp != NULL)
		temp->prev = NewNode;
	(*stack)->next = newNode;
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
	stack_t temp;
	(void)line_number;

	for (temp = (*stack)->next; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
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
	printf("testing nop func \n ");
}
