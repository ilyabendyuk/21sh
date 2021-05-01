#include <minishell.h>

void	*pop(t_queue **queue, void *del)
{
	t_queue	*q;

	if (queue && *queue)
	{
		q = *queue;
		if (q->data == del)
			return (pop_front(queue));
		while (q)
		{
			if (q->data == del)
			{
				q->prev->next = q->next;
				if (q->next)
					q->next->prev = q->prev;
				q->data = NULL;
				q->next = NULL;
				q->prev = NULL;
				free(q);
				q = NULL;
				return (del);
			}
			q = q->next;
		}
	}
	return (NULL);
}
