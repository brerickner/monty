#include "monty.h"
/**
 * add - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that adds top two values on stack
  * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n"
			, line_number);
		free_stack(stack);
		fclose(exttokens.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->n += (*stack)->next->n;
	pop(stack, line_number);

}
/**
 * sub - stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description: function that subtracts top two values on stack
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n"
			, line_number);
		free_stack(stack);
		fclose(exttokens.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mul- stack_t **stack, unsigned int line_number
 * @stack: pointer to head of doubly linked list
 * @line_number: line number
 * description:  function that multiplies top two values on stack
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n"
			, line_number);
		free_stack(stack);
		fclose(exttokens.file);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->next->prev->n;
	pop(stack, line_number);

}
