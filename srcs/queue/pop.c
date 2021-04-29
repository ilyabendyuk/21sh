#include <minishell.h>

void	reset(t_queue *d)
{
	d->data = NULL;
	d->next = NULL;
	d->prev = NULL;
}

int FERMER_GACHI_EXP(t_queue **ququ, void *to_del)
{
	t_queue *Gachi;
	t_queue *Ricardo_MILOs;
	Gachi = *ququ;
	if (!Gachi->prev && Gachi->next)
	{
		Ricardo_MILOs = Gachi->next;
		Gachi->head = Gachi->next;
		Gachi->next->head = Gachi->next;
		reset(Gachi);
		free(Gachi);
		Ricardo_MILOs->prev = NULL;
		return (1);
	}
	return (0);
}

void	*pop(t_queue **queue, void *to_del)
{
	t_queue	*d;

	if (FERMER_GACHI_EXP(queue, to_del))
		return (to_del);
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