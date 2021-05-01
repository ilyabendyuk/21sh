#include <minishell.h>

int	validate_redirs(t_queue *args)
{
	char	*redir;
	int		count;
	char	*tmp;

	count = -1;
	redir = args->data;
	while (redir[++count])
	{
		if (count == 1 && redir[0] != redir[count])
		{
			validation_error(NULL, redir + count);
			return (0);
		}
		if (count == 2)
		{
			tmp = ft_strndup(redir + count, 2);
			validation_error(NULL, tmp);
			ft_free(tmp);
			return (0);
		}
	}
	if (args->next && !ft_strequ(args->next->data, "|")
		&& !ft_strequ(args->next->data, ";"))
		return (1);
	return (validation_error(args->next, NULL));
}

int	aggro_error(char *str)
{
	fd_printf(2, "21sh: %s: Bad file descriptor\n", str);
	return (0);
}

int	validate_aggro(t_queue *args)
{
	char	*aggr;
	char	*start;

	aggr = args->data;
	if (ft_atoll(aggr) > 2559)
		return (aggro_error(aggr));
	while (*aggr && is_number(*aggr))
		aggr++;
	aggr += 2;
	if (*aggr == '\0')
		return (validation_error(args->next, NULL));
	start = aggr;
	while (*aggr && is_number(*aggr))
		aggr++;
	if (*aggr == '\0' && ft_atoll(start) > 2559)
		return (aggro_error(start));
	return (1);
}

int	validate_tokens(t_queue *args, int token_count)
{
	if (!args)
		return (0);
	while (args)
	{
		if (check_redir(args->data) > 0)
		{
			if (check_redir(args->data) == 2)
			{
				if (validate_aggro(args) == 0)
					return (0);
			}
			else if (validate_redirs(args) == 0)
				return (0);
		}
		if (ft_strequ(args->data, "|") || ft_strequ(args->data, ";"))
		{
			if (token_count == 0)
				return (validation_error(args, NULL));
			token_count = -1;
		}
		token_count++;
		args = args->next;
	}
	return (1);
}
