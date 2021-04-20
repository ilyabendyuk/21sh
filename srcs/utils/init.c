/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:52 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		init_globals(void)
{
	g_pid = 0;
	g_err = 0;
	g_sigquit = 0;
	g_sigint = 0;
}

t_comand	*init_cmd_struct(void)
{
	t_comand *cmd;

	cmd = (t_comand *)ft_malloc(sizeof(t_comand));
	cmd->cmd = NULL;
	cmd->redir = NULL;
	cmd->args = NULL;
	return (cmd);
}
