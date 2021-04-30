#include <minishell.h>

//static void	set_GACHI_TAIL(t_queue **queue, t_queue *tail)
//{
//	t_queue	*q;
//
//	q = (*queue)->head;
//	while (q)
//	{
//		q->tail = tail;
//		q = q->next;
//	}
//}
//
//int FERMER_GACHI_EXP(t_queue **ququ, void *to_del)
//{
//	t_queue *Gachi;
//	t_queue *Ricardo_MILOs;
//
//	Gachi = (*ququ)->head;
//	if (!Gachi->prev && (*ququ)->data == to_del)
//	{
//		if (Gachi->next)
//		{
//			Ricardo_MILOs = Gachi->next;
//			Ricardo_MILOs->prev = NULL;
//			Ricardo_MILOs->head = Gachi->next;
//		}
//		else
//			Gachi->head = Gachi->head;
//		Gachi->next = NULL;
//		Gachi->prev = NULL;
//		Gachi->head = NULL;
//		Gachi->data = NULL;
//		Gachi->tail = NULL;
//		free(Gachi);
//		Gachi = NULL;
//		return (1);
//	}
//	return (0);
//}
//
//void	*pop(t_queue **queue, void *to_del)
//{
//	t_queue	*d;
//	void *data;
//
//	if ((*queue) && (*queue)->data == to_del && (*queue)->prev == NULL)
//		return (pop_front(queue));
//	if (queue && *queue)
//	{
//		d = (*queue)->head;
//		while (d)
//		{
//			if (d->data == to_del)
//			{
//				if (d->next == NULL) {
//					set_GACHI_TAIL(queue, d->prev);
//				}
//				data = d->data;
//				d->prev->next = d->next;
//				d->next->prev = d->prev;
//				d->next = NULL;
//				d->prev = NULL;
//				d->data = NULL;
//				d->head = NULL;
//				d->tail = NULL;
//				ft_free(d);
//				d = NULL;
//				return (data);
//			}
//			d = d->next;
//		}
//	}
//	return (NULL);
//}