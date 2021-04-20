/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:03 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*join_queue(t_queue *args)
{
	char	*joined;
	char	*tmp;
	char	*tmp_joined;

	joined = ft_strdup("\0");
	tmp = NULL;
	tmp_joined = NULL;
	while (args)
	{
		tmp = (char *)pop_front(&args);
		tmp_joined = joined;
		joined = ft_strjoin(tmp_joined, tmp);
		(tmp_joined) ? free(tmp_joined) : NULL;
		(tmp) ? free(tmp) : NULL;
	}
	return (joined);
}
