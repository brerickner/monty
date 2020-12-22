#include "monty.h"
/**
* free_stack - function to free stack
* @stack: double pointer to stack
* Return: void
*/

void free_stack(stack_t **stack)
{

if (!*stack)
	return;

while (stack != NULL && (*stack)->next != NULL)
{
*stack = (*stack)->next;
free((*stack)->prev);
}
free(*stack);
*stack = NULL;
}
