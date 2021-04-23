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

int	validate_tokens(t_queue *args)
{
	int		token_count;

	token_count = 0;
	if (!args)
		return (0);
	while (args)
	{
		if (check_redir(args->data) == 1)
		{
			if (validate_redirs(args) == 0)
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
