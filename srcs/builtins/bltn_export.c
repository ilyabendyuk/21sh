/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:21:52 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**assemble_env_export(t_queue *env)
{
	char	**res_env;
	t_env	*token;
	char	*env_line;
	char	*tmp;

	res_env = NULL;
	tmp = NULL;
	while (env)
	{
		token = env->data;
		if (token->value[0])
		{
			tmp = ft_strjoin_tripple("\"", token->value, "\"");
			env_line = ft_strjoin_tripple(token->name, "=", tmp);
			(tmp) ? free(tmp) : NULL;
		}
		else
			env_line = ft_strdup(token->name);
		res_env = realloc_2d_array(res_env, env_line);
		(env_line) ? free(env_line) : NULL;
		env = env->next;
	}
	return (res_env);
}

void	print_env_no_args(t_queue *env)
{
	char	**e;
	int		i;

	i = 0;
	e = assemble_env_export(env);
	e = sort_2d_array(&e);
	while (e[i])
	{
		ft_printf("declare -x %s\n", e[i]);
		i++;
	}
	free_2d_array(e);
}

void	check_and_replace_env(t_queue *env, char *arg)
{
	int		i;
	char	*name;
	char	*val;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '=')
	{
		g_err = 1;
		ft_printf("minishell: export: %s: not a valid identifier\n", arg);
		return ;
	}
	name = ft_strndup(arg, i);
	val = ft_strdup(arg + i + 1);
	update_env(&env, name, val);
	free(name);
	free(val);
}

void	bltn_export(t_queue *env, char **args)
{
	int		i;

	i = 1;
	if (!args[1])
		print_env_no_args(env);
	else
	{
		while (args[i])
		{
			check_and_replace_env(env, args[i]);
			i++;
		}
	}
}
