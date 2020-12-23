#include "monty.h"

/**
* swap - stack_t **stack, unsigned int line_number
* @stack: pointer to head of doubly linked list
* @line_number: line number
* description: function that swaps top two elements on stack
* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack) == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n"
		, line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
