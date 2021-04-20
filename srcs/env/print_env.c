/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:13 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env(t_queue *env)
{
	t_queue	*e;
	t_env	*inst;

	e = env;
	while (e)
	{
		inst = (t_env *)e->data;
		if (inst->value[0])
			ft_printf("%s=%s\n", inst->name, inst->value);
		e = e->next;
	}
}
