#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1024];

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *tmp;
	
	tmp = *stack;
	
	if (tmp == NULL)
	{
		new_node = malloc(sizeof(stack_t));
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node = malloc(sizeof(stack_t));
		new_node->next = *stack;
		new_node->prev = NULL;
		tmp->prev = new_node;
		*stack = new_node;
	}
}


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	tmp = *stack;
	
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


void function_selector(char *str, stack_t **stack, unsigned int line_number)
{
	char *token;
	int i;
	instruction_t functions[] = {
	
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
}

void function_runner(char *str, stack_t **stack)
{
	char *token, tmp[1024];
	unsigned int line_number;
	
	line_number = 1;
	
	token = strtok(str, "\n");

		     
	while (token != NULL)
	{
		memset(tmp, 0, sizeof(tmp));
		strcpy(tmp, token);
		printf("%s\n", tmp);
		function_selector(tmp, stack, line_number);
		token = strtok(NULL, "\n");
	}
}

int main(int argc, char *argv[])
   {
	FILE *fp;
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
	char *token, tmp[1024];
	unsigned int line_number;
	stack_t **stack;
	
	*stack = NULL;
	line_number = 1;

       if (argc != 2) {
           fprintf(stderr, "Usage: %s <file>\n", argv[0]);
           exit(EXIT_FAILURE);
       }

       strcat = fopen(argv[1], "r");
       if (stream == NULL) {
           perror("fopen");
           exit(EXIT_FAILURE);
       }

       while ((nread = getline(&line, &len, stream)) != -1) {
           printf("Retrieved line of length %zu:\n", nread);
           fwrite(line, nread, 1, stdout);
       }

       free(line);
       fclose(fp);
       exit(EXIT_SUCCESS);
   }
