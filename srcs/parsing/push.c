#include <minishell.h>

t_redir	*create_aggro_redir(char *aggr)
{
	t_redir	*redir;
	char	*tmp;

	tmp = aggr;
	redir = (t_redir *)ft_malloc(sizeof(t_redir));
	while (*aggr && *aggr != '<' && *aggr != '>')
		aggr++;
	redir->fname = ft_strndup(tmp, aggr - tmp);
	redir->id = ft_strndup(aggr, 2);
	redir->fname2 = ft_strdup(aggr + 2);
	return (redir);
}

void	push_redir(t_queue *cmd, t_queue **tokens)
{
	t_redir	*redir;

	if (ft_strstr((*tokens)->data, ">&")
		|| ft_strstr((*tokens)->data, "<&"))
		return (push_back(&(((t_comand *)cmd->data)->redir),
				create_aggro_redir((*tokens)->data)));
	redir = (t_redir *)ft_malloc(sizeof(t_redir));
	redir->id = ft_strdup((*tokens)->data);
	redir->fname = ft_strdup((*tokens)->next->data);
	redir->fname2 = NULL;
	push_back(&(((t_comand *)cmd->data)->redir), redir);
	*tokens = (*tokens)->next;
}

void	push_args(t_queue *cmd, t_queue *token)
{
	((t_comand *)cmd->data)->args
		= realloc_2d_array(((t_comand *)cmd->data)->args, token->data);
}

t_queue	*push_pipe(t_queue *cmd, t_queue *tokens)
{
	int		flag;

	tokens = tokens->next;
	flag = 0;
	push_back(&cmd, init_cmd_struct());
	while (tokens && ft_strequ(tokens->data, ";") == 0
		&& ft_strequ(tokens->data, "|") == 0)
	{
		if (flag == 0)
		{
			if (check_redir(tokens->data) > 0)
				((t_comand *)get_last_elem(cmd)->data)->cmd = ft_strdup("");
			else
				((t_comand *)get_last_elem(cmd)->data)->cmd
					= ft_strdup(tokens->data);
		}
		if (check_redir(tokens->data) > 0)
			push_redir(get_last_elem(cmd), &tokens);
		else
			push_args(get_last_elem(cmd), tokens);
		flag++;
		tokens = tokens->next;
	}
	return (tokens);
}
