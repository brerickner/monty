#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"
/**
 * getfunc - char *opFind, stack_t **stack, unisigned int line_number
 * @opFind: opcode found
 * @stack: pointer to head node of doubly linked list
 * @line_number: line number
 * description: get opcode corresponding instructions
 * Return: void
 */
void getfunc(char *opFind, stack_t **stack, unsigned int line_number)
{
	unsigned int i = NULL;
	/* instruction_t *x = malloc(sizeof(instruction_t)); */
	instruction_t monty_instructions[] = {
		{"pint", pint},
		{"nop", nop},
		{"add", add},
		{"pop", pop},
		{"swap", swap},
		{"sub", sub},
		{"mul", mul},
		{"pall", pall},
		{NULL, NULL}
	};
/*
 * if (x == NULL)
 * return (NULL);
 * x = monty_instructions;
 * valgrind errors line 17, 19, 33, 50, 72
 */
	for (i = 0; monty_instructions[i].f != NULL; i++)
	{
		if (strcmp(opFind, monty_instructions[i].opcode) == 0)
		{
/* printf("match found\n"); */
/* printf("%s\n", opFind); */
			monty_instructions[i].f(stack, line_number);
			return;
		}
	}
	free_stack(stack);
	fclose(exttokens.file);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opFind);
/*	free_stack(stack);*/
	/* printf("made it past freeing stack when match not found\n"); */
/*	free(exttokens.file); */
	exit(EXIT_FAILURE);
}
/**
 * main - int argc, char **argv
 * @argc: number of arguments
 * @argv: arguments passed to monty
 * description: get opcode corresponding instructions
 * Return: EXIT_FAILURE if failed. Else EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	unsigned int lineCount = 1, numFind;
	char opFind[5] = {0};
	char *line = NULL;
	size_t buf = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	exttokens.file = file;
	while (fscanf(file, "%s", opFind) != EOF)
	{
		if (strcmp(opFind, "push") == 0)
		{
			numFind = fscanf(file, "%d", &exttokens.numFind);
			if (numFind != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n"
					, lineCount + 1);
				fclose(exttokens.file), free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			push(&stack, lineCount), lineCount++;
			continue;
		}
		lineCount++;
		getline(&line, &buf, file);
		getfunc(opFind, &stack, lineCount);
	} /*mystery bracket*/
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
