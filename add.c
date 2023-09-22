#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int len = 0, result;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(infos.file);
		free(infos.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	result = hd->n + hd->next->n;
	hd->next->n = result;
	*head = hd->next;
	free(hd);
}

