/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:06 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_env_var(t_queue *envir, char *name)
{
	t_queue *env;

	env = envir->head;
	while (env)
	{
		if (ft_strequ(((t_env *)env->data)->name, name))
		{
			(name) ? free(name) : NULL;
			return (((t_env *)env->data)->value);
		}
		env = env->next;
	}
	(name) ? free(name) : NULL;
	return (NULL);
}
