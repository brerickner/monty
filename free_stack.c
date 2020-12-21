#include "monty.h"
/**
* free_stack - function to free stack
* @stack: double pointer to stack
* Return: void
*/

void free_stack(stack_t **stack)
{
stack_t *temp = *stack;

while (*stack != NULL)
{
    temp = (*stack)->next;
    free(stack);
    (*stack) = temp;
}
}
