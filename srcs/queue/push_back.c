#include <minishell.h>

//static void	set_GACHI_TAIL(t_queue **queue, t_queue *last)
//{
//	t_queue	*q;
//	t_queue *head;
//
//	q = (*queue)->head;
//	head = q;
//	while (q)
//	{
//		q->tail = last;
//		q->head = head;
//		q = q->next;
//	}
//}
//
//void	push_back(t_queue **q, void *data)
//{
//	t_queue	*new;
//
//	new = (t_queue *)ft_malloc(sizeof(t_queue));
//	new->data = data;
//	if (!(*q))
//	{
//		*q = new;
//		new->prev = NULL;
//		new->next = NULL;
//		new->tail = new;
//		new->head = new;
//	}
//	else
//	{
//		new->next = NULL;
//		new->tail = new;
//		new->prev = (*q)->tail;
//		(*q)->tail->next = new;
////		(*q)->tail = new;
//		set_GACHI_TAIL(q, new);
////		new->tail = new;
////		new->head = (*q)->head;
////		new->prev = (*q)->tail;
////		(*q)->tail->next = new;
////		(*q)->tail = new;
////		new->next = NULL;
//	}
//}

t_queue	*get_last_elem(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue->next)
		queue = queue->next;
	return (queue);
}

void				push_back(t_queue **queue, void *room)
{
	t_queue	*last;
	t_queue	*new;

	new = (t_queue *)ft_malloc(sizeof(t_queue));
	new->data = room;
	new->next = NULL;
	if (!(last = get_last_elem(*queue)))
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