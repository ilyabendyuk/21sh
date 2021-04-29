#include <minishell.h>

void	push_back(t_queue **q, void *data)
{
	t_queue	*new;

	new = (t_queue *)ft_malloc(sizeof(t_queue));
	new->data = data;
	if (!(*q))
	{
		*q = new;
		new->prev = NULL;
		new->next = NULL;
		new->tail = new;
		new->head = new;
	}
	else
	{
		new->tail = new;
		new->head = (*q)->head;
		new->prev = (*q)->tail;
		(*q)->tail->next = new;
		(*q)->tail = new;
		new->next = NULL;
	}
}