/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:12 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*parse_env_var(t_queue *env, char **line)
{
	char *start;

	if (**line == '~')
	{
		(*line)++;
		return (ft_strdup(get_env_var(env, ft_strdup("HOME"))));
	}
	(*line)++;
	start = *line;
	if (**line == '?')
	{
		(*line)++;
		return (ft_itoa_sh((int)g_prev_err));
	}
	while (**line && **line != ' ' && **line != '\0' && **line != ';'
			&& **line != '|' && **line != '>' && **line != '<' &&
			**line != '\'' && **line != '\"' && **line != '\\' && **line != '$')
		(*line)++;
	return (ft_strdup(get_env_var(env, ft_strndup(start, *line - start))));
}
