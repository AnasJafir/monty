#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int sub, Node;

	current = *head;
	for (Node = 0; current != NULL; Node++)
		current = current->next;
	if (Node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(infos.file);
		free(infos.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	sub = current->next->n - current->n;
	current->next->n = sub;
	*head = current->next;
	free(current);
}

