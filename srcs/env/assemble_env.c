/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:00 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**assemble_env(t_queue *envir)
{
	t_queue *env;
	char	**res_env;
	t_env	*token;
	char	*env_line;

	env = envir;
	res_env = NULL;
	while (env)
	{
		token = env->data;
		env_line = ft_strjoin_tripple(token->name, "=", token->value);
		res_env = realloc_2d_array(res_env, env_line);
		(env_line) ? free(env_line) : NULL;
		env = env->next;
	}
	return (res_env);
}
