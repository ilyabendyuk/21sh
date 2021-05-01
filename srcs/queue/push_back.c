#include <minishell.h>

t_queue	*get_last_elem(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue->next)
		queue = queue->next;
	return (queue);
}

void	push_back(t_queue **queue, void *room)
{
	t_queue	*last;
	t_queue	*new;

	new = (t_queue *)ft_malloc(sizeof(t_queue));
	new->data = room;
	new->next = NULL;
	last = get_last_elem(*queue);
	if (!last)
	{
		*queue = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
}
