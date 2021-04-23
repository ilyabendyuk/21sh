#include <minishell.h>

void	reset(t_queue *d)
{
	d->data = NULL;
	d->next = NULL;
	d->prev = NULL;
}

void	*pop(t_queue **queue, void *to_del)
{
	t_queue	*d;

	if (queue && *queue)
	{
		d = (*queue)->head;
		while (d)
		{
			if (d->data == to_del)
			{
				d->prev->next = d->next;
				if (d->next)
					d->next->prev = d->prev;
				else
					d->tail = d->prev;
				if (d == d->head && d->next)
					d->next->head = d->next;
				reset(d);
				free(d);
				return (to_del);
			}
			d = d->next;
		}
	}
	return (NULL);
}
