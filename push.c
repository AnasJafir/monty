#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int a, b = 0, f = 0;

	if (infos.arg)
	{
		if (infos.arg[0] == '-')
			b++;
		for (; infos.arg[b] != '\0'; b++)
		{
			if (infos.arg[b] > 57 || infos.arg[b] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(infos.file);
			free(infos.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(infos.file);
		free(infos.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	a = atoi(infos.arg);
	if (infos.lifi == 0)
		addnode(head, a);
	else
		addqueue(head, a);
}

