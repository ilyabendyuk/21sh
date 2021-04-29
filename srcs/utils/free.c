#include <minishell.h>

void 	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_redirs(t_queue *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = (t_redir *)pop_front(&redir);
		ft_free(tmp->fname);
		ft_free(tmp->id);
		ft_free(tmp->fname2);
		ft_free(tmp);
	}
}

void	free_cmd(t_comand *cmd)
{
	ft_free(cmd->cmd);
	cmd->cmd = NULL;
	free_2d_array(cmd->args);
	cmd->args = NULL;
	free_redirs(cmd->redir);
	cmd->redir = NULL;
}

void	free_comands(t_queue *cmd)
{
	t_comand	*tmp;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = pop_front(&cmd);
		free_cmd(tmp);
		free(tmp);
		tmp = NULL;
	}
}

void	free_tokens(t_queue *tokens)
{
	char	*to_free;

	if (!tokens)
		return ;
	while (tokens)
	{
		to_free = pop_front(&tokens);
		ft_free(to_free);
	}
}
