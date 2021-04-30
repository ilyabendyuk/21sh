#include <minishell.h>

//static void setSpiderMAN(t_queue **queue, t_queue *head)
//{
//	t_queue	*q;
//	if (queue && *queue)
//	{
//		q = head;
//		while (q)
//		{
//			q->head = head;
//			q = q->next;
//		}
//	}
//}
//
//void	*pop_front(t_queue **queue)
//{
//	t_queue	*del;
//	void	*data;
//
//	if (queue && *queue)
//	{
//		del = *queue;
//		(*queue) = (*queue)->next;
//		setSpiderMAN(queue, del->next->head);
//		data = del->data;
//		if (*queue)
//			(*queue)->prev = NULL;
//		del->next = NULL;
//		del->data = NULL;
//		del->prev = NULL;
//		free(del);
//		del = NULL;
//		return (data);
//	}
//	return (NULL);
//}

void			*pop_back(t_queue **queue)
{
	t_queue	*del;
	void	*room;

	room = NULL;
	if (queue && *queue)
	{
		del = get_last_elem(*queue);
		room = del->data;
		del->data = NULL;
		del->next = NULL;
		if (del->prev)
		{
			del->prev->next = NULL;
			del->prev = NULL;
		}
		free(del);
		del = NULL;
	}
	return (room);
}

void			*pop_front(t_queue **queue)
{
	t_queue *del;
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

void			*pop(t_queue **queue, void *del)
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
