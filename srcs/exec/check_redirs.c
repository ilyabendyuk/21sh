/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:25 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		try_open_redirs(t_shell *shell, t_redir *redir)
{
	int	flag;

	flag = get_path(shell->env->head, &(redir->fname), 1);
	if (redir->id[0] == '<')
	{
		if (g_fd_in != -2)
			close(g_fd_in);
	}
	if (redir->id[0] == '>')
	{
		if (g_fd_out != -2)
			close(g_fd_out);
	}
	if (ft_strequ(redir->id, "<<") || ft_strequ(redir->id, "<"))
		g_fd_in = open(redir->fname, O_RDONLY);
	if (ft_strequ(redir->id, ">"))
		g_fd_out = open(redir->fname, O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR | \
			S_IWUSR | S_IRGRP | S_IROTH);
	if (ft_strequ(redir->id, ">>"))
		g_fd_out = open(redir->fname, O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | \
			S_IWUSR | S_IRGRP | S_IROTH);
	return (flag);
}

void	error_redir(int flag, char *tmp_redir)
{
	DIR *dir;

	dir = NULL;
	dir = opendir(tmp_redir);
	if (flag == OPEN_ERR)
		fd_printf(2, "minishell: %s: No such file or directory\n", tmp_redir);
	else if (dir)
		fd_printf(2, "minishell: %s: Is a directory\n", tmp_redir);
	else
		fd_printf(2, "minishell: %s: Permission denied\n", tmp_redir);
	if (dir)
		closedir(dir);
}

int		open_redirs_and_check(t_shell *shell, t_comand *cmd)
{
	t_queue	*redir;
	char	*tmp_redir;
	int		flag;

	redir = cmd->redir;
	if (redir)
	{
		while (redir)
		{
			tmp_redir = ft_strdup(((t_redir *)redir->data)->fname);
			flag = try_open_redirs(shell, redir->data);
			if ((g_fd_in == -1 || g_fd_out == -1) || flag == OPEN_ERR)
			{
				error_redir(flag, tmp_redir);
				g_err = 1;
				free(tmp_redir);
				return (0);
			}
			free(tmp_redir);
			redir = redir->next;
		}
	}
	return (1);
}
