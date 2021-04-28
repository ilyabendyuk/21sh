#include <minishell.h>

void heredoc(t_shell *shell, char *here) //TODO EOF
{
	int		fd[2];
	char	*line;

	dup2(shell->g_save_in, 0);
	pipe(fd);
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, here))
			break ;
		write(fd[1], line, ft_strlen_shell(line));
		write(fd[1], "\n", 1);
		line = ft_free(line);
	}
	line = ft_free(line);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

int	try_open_redirs(t_shell *shell, t_redir *redir)
{
	int	flag;

	if (redir->id[0] == '<')
	{
		if (shell->g_fd_in != -2)
			close(shell->g_fd_in);
	}
	if (redir->id[0] == '>')
	{
		if (shell->g_fd_out != -2)
			close(shell->g_fd_out);
	}
	if (ft_strequ(redir->id, "<<"))
		heredoc(shell, redir->fname);
	flag = get_path(shell->env->head, &(redir->fname), 1);
	if (ft_strequ(redir->id, "<"))
		shell->g_fd_in = open(redir->fname, O_RDONLY);
	if (ft_strequ(redir->id, ">"))
		shell->g_fd_out = open(redir->fname, O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR | \
			S_IWUSR | S_IRGRP | S_IROTH);
	if (ft_strequ(redir->id, ">>"))
		shell->g_fd_out = open(redir->fname, O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | \
			S_IWUSR | S_IRGRP | S_IROTH);
	return (flag);
}

void	error_redir(int flag, char *tmp_redir)
{
	DIR	*dir;

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

int	open_redirs_and_check(t_shell *shell, t_comand *cmd)
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
			if ((shell->g_fd_in == -1 || shell->g_fd_out == -1)
				|| flag == OPEN_ERR)
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
