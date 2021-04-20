/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:21:55 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	del_env_instanse(t_queue *env, char *arg)
{
	t_env	*inst;
	t_queue	*tmp;

	tmp = env;
	if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '=')
	{
		g_err = 1;
		ft_printf("minishell: export: %s: not a valid identifier\n", arg);
		return ;
	}
	while (tmp)
	{
		inst = tmp->data;
		if (ft_strequ(arg, inst->name))
		{
			pop(&env, inst);
			(inst->name) ? free(inst->name) : NULL;
			(inst->value) ? free(inst->value) : NULL;
			free(inst);
			return ;
		}
		tmp = tmp->next;
	}
}

void	bltn_unset(t_queue *env, char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		del_env_instanse(env->head, args[i]);
		i++;
	}
}
