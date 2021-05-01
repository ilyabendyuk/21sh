#include <minishell.h>

void	*pop_front(t_queue **queue)
{
	t_queue	*del;
	void	*room;

	if (queue && *queue)
	{
		del = *queue;
		room = del->data;
		(*queue) = (*queue)->next;
		if (*queue)
			(*queue)->prev = NULL;
		del->next = NULL;
		del->data = NULL;
		del->prev = NULL;
		free(del);
		del = NULL;
		return (room);
	}
	return (NULL);
}
