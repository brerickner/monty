#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"
	
int main(int argc, char **argv)
{
	FILE *file;
	char *theFile = argv[1];
	char *line = NULL;
	unsigned int i;
	stack_t **stack = NULL;
	unsigned int lineCount = 1;
	/*tokenizer variables*/
	char opFind[BUFFER] = {0};
	unsigned int numFind;
	char newLine = 0;
	instruction_t ops[] = {
		{"nop", nop},
		{"\0", NULL}
		};
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
    printf("number of lines: %d\n", lineCount - 1);
    printf("%s %d\n", opFind, numFind);
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, opFind) == 0)
		{
			(ops[i].f(stack, 3));
			/*break;*/
		}
		
		else
		{
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
			exit(EXIT_FAILURE);
		}
	}
    } /*mystery bracket*/
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}
