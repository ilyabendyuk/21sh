/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:48 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_skip_sep_cmd(t_shell *shell, char **line)
{
	t_queue *tmp;

	tmp = NULL;
	if (**line == '<' || **line == '>')
	{
		while (**line == '<' || **line == '>')
		{
			push_back(&tmp, ft_strndup(*line, 1));
			(*line)++;
		}
		if (tmp)
			push_back(&(shell->args), join_queue(tmp));
		return ;
	}
	if (ft_is_sep_cmd(**line))
	{
		push_back(&(shell->args), ft_strndup(*line, 1));
		(*line)++;
	}
}

char	*parse_shield(char **line)
{
	char *shield;

	(*line)++;
	shield = ft_strndup(*line, 1);
	if (!(**line))
		return (shield);
	(*line)++;
	return (shield);
}

char	*parse_token(t_shell *shell, char *line, t_queue **to)
{
	t_queue *tokens;

	tokens = *to;
	if (ft_skip_spaces(&line) > 0 || ft_is_sep_cmd(*line))
	{
		(tokens) ? push_back(&shell->args, join_queue(tokens)) : NULL;
		tokens = NULL;
		ft_skip_sep_cmd(shell, &line);
	}
	if (*line == '$' || *line == '~')
		push_back(&tokens, parse_env_var(shell->env, &line));
	else if (*line == '\\')
		push_back(&tokens, parse_shield(&line));
	else if (*line == '\'')
		push_back(&tokens, parse_single_quote(&line));
	else if (*line == '\"')
		push_back(&tokens, parse_double_quote(shell, &line, NULL));
	else if (*line != '\0' && !ft_isspace(*line) && !ft_is_sep_cmd(*line))
	{
		push_back(&tokens, ft_strndup(line, 1));
		line++;
	}
	*to = tokens;
	return (line);
}

void	parse_comands(t_shell *shell, char *line)
{
	t_queue	*tokens;

	tokens = NULL;
	shell->args = NULL;
	while (*line)
		line = parse_token(shell, line, &tokens);
	(tokens) ? push_back(&shell->args, join_queue(tokens)) : NULL;
}
