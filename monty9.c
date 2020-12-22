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
	unsigned int i;
	/* instruction_t *x = malloc(sizeof(instruction_t)); */
	instruction_t monty_instructions[] = {
		{"pint", pint},
/*		{"push", push}, */
		{"nop", nop},
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
	fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
	free_stack(stack);
	/* printf("made it past freeing stack when match not found\n"); */
	free(exttokens.file);
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
	FILE *file;
	char *theFile = argv[1];
	unsigned int lineCount = 1, numFind;
	char opFind[5] = {0};
	stack_t *stack = NULL;

/*if no file given or more than one arg given */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(theFile, "r");
/*if unable to open file*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", theFile);
		exit(EXIT_FAILURE);
	}
	exttokens.file = file;
	while (fscanf(file, "%s", opFind) != EOF)
	{
		if (strcmp(opFind, "push") == 0)
		{
			fscanf(file, "%u", &numFind);
			exttokens.numFind = numFind;
			push(&stack, lineCount);
			continue;
		}
		/* printf("%s %d\n", opFind, numFind); */
		getfunc(opFind, &stack, lineCount);
	} /*mystery bracket*/
/*      free(file); */
/*free(opFind);*/
	fclose(file);
/*        printf("end of program\n");*/
	return(EXIT_SUCCESS);

}
