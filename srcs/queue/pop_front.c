/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:06 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*pop_front(t_queue **queue)
{
	t_queue *del;
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
		(*queue) ? (*queue)->head = *queue : NULL;
		(*queue) ? (*queue)->prev = NULL : NULL;
		del->next = NULL;
		del->data = NULL;
		del->prev = NULL;
		free(del);
		del = NULL;
		return (data);
	}
	return (NULL);
}
