/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:08 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	push_back(t_queue **q, void *data)
{
	t_queue	*new;

	new = (t_queue *)ft_malloc(sizeof(t_queue));
	new->data = data;
	if (!(*q))
	{
		*q = new;
		new->prev = NULL;
		new->next = NULL;
		new->tail = new;
		new->head = new;
	}
	else
	{
		new->tail = new;
		new->head = (*q)->head;
		new->prev = (*q)->tail;
		(*q)->tail->next = new;
		(*q)->tail = new;
		new->next = NULL;
	}
}
