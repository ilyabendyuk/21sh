#include <minishell.h>

void	*pop_front(t_queue **queue)
{
	t_queue	*del;
	void	*data;

	if (queue && *queue)
	{
		if ((*queue)->head)
			(*queue) = (*queue)->head;
		else
			return (NULL);
		del = *queue;
		data = del->data;
		(*queue) = (*queue)->next;
		if (*queue)
		{
			(*queue)->head = *queue;
			(*queue)->prev = NULL;
		}
		del->next = NULL;
		del->data = NULL;
		del->prev = NULL;
		free(del);
		del = NULL;
		return (data);
	}
	return (NULL);
}
