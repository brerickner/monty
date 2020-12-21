#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

stack_t *getfunc(char *opcode, stack_t **stack, unsigned int line_number)
{
        unsigned int i;
/*	instruction_t *x = malloc(sizeof(instruction_t)); */
	instruction_t monty_instructions[] = {
                {"nop", nop},
                {"\0", NULL}
        };
/*	if (x == NULL)
	return (NULL); */
/*	x = monty_instructions; */
/*valgrind errors line 17, 19, 33, 50, 72 */
        for (i = 0; monty_instructions[i].opcode != NULL; i++)
        {
		if (*(monty_instructions[i]).opcode == *opcode)
		{
                        printf("match found\n");
			monty_instructions[i].f(stack, line_number);
                }
                if (monty_instructions[i].opcode == NULL)
                {
                        fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
                        exit(EXIT_FAILURE);
                }
        }
	return (*stack);
}
int main(int argc, char **argv)
{
        FILE *file;
        char *theFile = argv[1];
        /*      unsigned int i; */
        unsigned int lineCount = 1;
        /*tokenizer variables*/
        char opFind[5] = {0};
	unsigned int numFind;
        char newLine = 0;
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
	/*tokenizer*/
	while(fscanf(file, "%s %u", opFind , &numFind) != EOF)
	{
		newLine = getc(file);
		while (newLine != EOF)
		{
			if (newLine == '\n')
			{
				lineCount += lineCount;
			}
			newLine = getc(file);
		}
		printf("number of lines: %d\n", lineCount);
		printf("%s %d\n", opFind, numFind);
	} /*mystery bracket*/
	getfunc(opFind, &stack, lineCount);
/*	free(file);*/
/*	free(opFind);*/
	fclose(file);
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
