#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

void getfunc(char *opFind, stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	/* instruction_t *x = malloc(sizeof(instruction_t)); */
	instruction_t monty_instructions[] = {
		{"pint", pint},
		{"push", push},
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
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opFind);
	free_stack(stack);
	/* printf("made it past freeing stack when match not found\n"); */
	free(exttokens.file);
	exit(EXIT_FAILURE);
}
int main(int argc, char **argv)
{
        FILE *file;
        char *theFile = argv[1];
        /*      unsigned int i; */
        unsigned int lineCount = 0;
        /*tokenizer variables*/
        char opFind[5] = {0};
	unsigned int numFind;
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
	/*tokenizer*/
	while (fscanf(file, "%s", opFind) != EOF)
	{
                if (strcmp(opFind, "push") == 0)
                {
			lineCount++;
                        fscanf(file, "%u", &numFind);
                        exttokens.numFind = numFind;
                        push(&stack, lineCount);
                }
		/* printf("number of lines: %d\n", lineCount); */
/*	        printf("%s %d\n", opFind, numFind); */
		lineCount++;
                getfunc(opFind, &stack, lineCount);
	} /*mystery bracket*/
/*      free(file); */
/*	free(opFind);*/
	fclose(file);
	/* printf("end of program\n");*/
	exit(EXIT_SUCCESS);
	return (0);
}
/*          for (i = 0; ops[i].opcode; i++)
            {

                    {
                            (ops[i].f(stack, 3));
                    }
                    else
                    {
                            fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
                            exit(EXIT_FAILURE);
                    }
		    }*/
