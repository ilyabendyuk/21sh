#include <minishell.h>

static char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*to_find)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[pos + i] == to_find[i] &&
				   (size_t)(pos + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}

void	ft_skip_sep_cmd(t_shell *shell, char **line)
{
	t_queue	*tmp;

	tmp = NULL;
	if (ft_strnstr(*line, ">&", 2) || ft_strnstr(*line, "<&", 2)) //check
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

int		starts_with(char *line, char *to_find)
{
	if (ft_strlen_shell(line) < ft_strlen_shell(to_find))
		return (0);
	while(*line && *to_find)
	{
		if (*line != *to_find)
			return (0);
		line++;
		to_find++;
	}
	return (1);
}

int 	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int 	check_aggro(char *line)
{
	if (!(starts_with(line, ">&") || starts_with(line, "<&"))  && !is_number(*line))
		return (0);
	if (starts_with(line, ">&") || starts_with(line, "<&"))
		return (1);
	while (*line && is_number(*line))
		line++;
	if (starts_with(line, ">&") || starts_with(line, "<&"))
		return (1);
	return (0);
}

char 	*create_aggro(char **line)
{
	char *start;
	char *ret;

	start = *line;
	while (is_number(**line))
		(*line)++;
	(*line) += 2;
	while(**line && !ft_is_sep_cmd(**line) && **line != ' ' && **line != '\t')
		(*line)++;
	ret = ft_strndup(start, *line - start);
	(*line)--;
	return (ret);
}

char	*parse_token(t_shell *shell, char *line, t_queue **to)
{
	t_queue	*tokens;

	tokens = *to;
	if (ft_skip_spaces(&line) > 0 || ft_is_sep_cmd(*line))
	{
		if (tokens)
			push_back(&shell->args, join_queue(tokens));
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
	else if (*line != '\0' && !ft_isspace(*line) && (!ft_is_sep_cmd(*line) || (ft_is_sep_cmd(*line) && *(line + 1) == '&')))
	{
		if ((ft_isspace(*(line - 1))  || !tokens) && check_aggro(line))
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
