/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:04 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
				(d->next) ? d->next->prev = d->prev : NULL;
				!(d->next) ? d->tail = d->prev : NULL;
				(d == d->head && d->next) ? d->next->head = d->next : NULL;
				d->data = NULL;
				d->next = NULL;
				d->prev = NULL;
				free(d);
				return (to_del);
			}
			d = d->next;
		}
	}
	return (NULL);
}
