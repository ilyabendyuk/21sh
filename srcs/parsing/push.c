#include <minishell.h>

void	push_redir(t_queue *cmd, t_queue **tokens)
{
	t_redir	*redir;

	ft_printf("{%s %s %s}\n", (*tokens)->prev->data, (*tokens)->data, (*tokens)->next->data);
	redir = (t_redir *)ft_malloc(sizeof(t_redir));
	redir->id = ft_strdup((*tokens)->data);
	redir->fname = ft_strdup((*tokens)->next->data);
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
			if (check_redir(tokens->data))
				((t_comand *)cmd->tail->data)->cmd = ft_strdup("");
			else
				((t_comand *)cmd->tail->data)->cmd = ft_strdup(tokens->data);
		}
		if (check_redir(tokens->data) == 1)
			push_redir(cmd->tail, &tokens);
		else
			push_args(cmd->tail, tokens);
		flag++;
		tokens = tokens->next;
	}
	return (tokens);
}
