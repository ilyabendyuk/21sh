/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:46 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*parse_single_quote(char **line)
{
	char	*start;
	char	*token;

	(*line)++;
	start = *line;
	while (**line && **line != '\'')
	{
		(*line)++;
	}
	token = ft_strndup(start, *line - start);
	(*line)++;
	return (token);
}

char	*parse_double_quote(t_shell *shell, char **line, t_queue *quote_args)
{
	char	*start;

	(*line)++;
	start = *line;
	while (**line && **line != '\"')
	{
		if (**line == '\\')
		{
			push_back(&quote_args, ft_strndup(start, *line - start));
			push_back(&quote_args, ft_strndup(*line + 1, 1));
			*line = *line + 2;
			start = *line;
		}
		else if (**line == '$' || **line == '~')
		{
			push_back(&quote_args, ft_strndup(start, *line - start));
			push_back(&quote_args, parse_env_var(shell->env, line));
			start = *line;
		}
		else
			(*line)++;
	}
	push_back(&quote_args, ft_strndup(start, *line - start));
	(*line)++;
	return (join_queue(quote_args));
}
