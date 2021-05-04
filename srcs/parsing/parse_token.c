#include <minishell.h>

void	ft_skip_sep_cmd(t_shell *shell, char **line)
{
	t_queue	*tmp;

	tmp = NULL;
	if (ft_strnstr(*line, ">&", 2) || ft_strnstr(*line, "<&", 2))
		return ;
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
	char	*shield;

	(*line)++;
	shield = ft_strndup(*line, 1);
	if (!(**line))
		return (shield);
	(*line)++;
	return (shield);
}

char	*join_tokens(t_shell *shell, t_queue **tokens, char *line)
{
	if (*tokens)
		push_back(&shell->args, join_queue(*tokens));
	*tokens = NULL;
	ft_skip_sep_cmd(shell, &line);
	return (line);
}

char	*parse_token(t_shell *shell, char *line, t_queue **to)
{
	t_queue	*tokens;

	tokens = *to;
	if (ft_skip_spaces(&line) > 0 || ft_is_sep_cmd(*line))
		line = join_tokens(shell, &tokens, line);
	if (*line == '$' || *line == '~')
		push_back(&tokens, parse_env_var(shell->env, &line));
	else if (*line == '\\')
		push_back(&tokens, parse_shield(&line));
	else if (*line == '\'')
		push_back(&tokens, parse_single_quote(&line));
	else if (*line == '\"')
		push_back(&tokens, parse_double_quote(shell, &line, NULL));
	else if (*line != '\0' && !ft_isspace(*line) && (!ft_is_sep_cmd(*line)
			|| (ft_is_sep_cmd(*line) && *(line + 1) == '&')))
	{
		if ((ft_isspace(*(line - 1)) || !tokens) && check_aggro(line))
			push_back(&tokens, create_aggro(&line));
		else
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
	if (tokens)
		push_back(&shell->args, join_queue(tokens));
}
