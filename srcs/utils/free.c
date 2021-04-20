/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:16 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_redirs(t_queue *redir)
{
	t_redir *tmp;

	while (redir)
	{
		tmp = (t_redir *)pop_front(&redir);
		(tmp->fname) ? free(tmp->fname) : NULL;
		(tmp->id) ? free(tmp->id) : NULL;
		(tmp) ? free(tmp) : NULL;
	}
}

void	free_cmd(t_comand *cmd)
{
	(cmd->cmd) ? free(cmd->cmd) : NULL;
	cmd->cmd = NULL;
	free_2d_array(cmd->args);
	cmd->args = NULL;
	free_redirs(cmd->redir);
	cmd->redir = NULL;
}

void	free_comands(t_queue *cmd)
{
	t_comand *tmp;

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
	char *to_free;

	if (!tokens)
		return ;
	while (tokens)
	{
		to_free = pop_front(&tokens);
		(to_free) ? free(to_free) : NULL;
	}
}
