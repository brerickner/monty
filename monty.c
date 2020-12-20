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
	char *cpyLine;
	size_t len = 0;
	ssize_t read;
	int i;
	stack_t **stack = NULL;
	unsigned int lineCount = 1;

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
	if (read = getline(&line, &len, file) == -1)
	{
		fprintf(stderr,"error getting line\n");
		printf("getline error\n");
		exit(EXIT_FAILURE);
	}
	cpyLine = strdup(line);
	tokenizer(cpyLine, " ");

	char **tokenizer(char *str, char *delim)
	{
		char *tokens;
		int index;

		for (index = 0, str[index]; index++)
		{
			if (str[index] == *delim)
			{
				if (str[index + 1] == *delim)
					continue;
			}
			if (str[index] == "\n")
				lineNum++;
		}
		tokens = malloc(sizeof(char) * BUFFER);
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		index = 0;
		tokens[index] = strtok(str, delim);
		index++;
		
	}

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, "nop") == 0)
		{
			(ops[i].f(stack, 3));
			break;
		}
		else
		{
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	exit(EXIT_SUCCESS);

	return (0);
}
