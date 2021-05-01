#include "minishell.h"

int	is_number_str(char *s)
{
	while (*s)
	{
		if (!is_number(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_aggreg(t_redir *redir, t_shell *shell)
{
	int	fd_left;
	int	fd_right;

	fd_right = (int)ft_atoll(redir->fname2);
	if (ft_strlen_shell(redir->fname) != 0)
		fd_left = (int) ft_atoll(redir->fname);
	else if (ft_strequ(redir->id, "<&"))
		fd_left = 0;
	else
		fd_left = 1;
	if (is_number_str(redir->fname2))
	{
		shell->g_fd_out = fd_right;
		dup2(fd_right, fd_left);
	}
	else if (ft_strequ(redir->fname2, "-"))
		close(fd_left);
	else
	{
		fd_printf(2, "21sh: %s: ambiguous redirect", redir->fname2);
		return (AGG_ERROR);
	}
	return (0);
}
