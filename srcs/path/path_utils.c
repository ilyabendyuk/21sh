#include <minishell.h>

int	count_decrease_lvl(char *path)
{
	int		i;

	i = 0;
	while (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/')
		i += 3;
	return (i);
}

void	path_err(char *cmd)
{
	DIR		*dir;
	int		fd;

	dir = NULL;
	fd = open(cmd, O_WRONLY);
	dir = opendir(cmd);
	if (fd == -1 && dir != NULL)
		fd_printf(2, "21sh: %s: is a directory\n", cmd);
	else if (fd != -1 && dir != NULL)
		fd_printf(2, "21sh: %s: Permission denied\n", cmd);
	else
		fd_printf(2, "21sh: %s: No such file or directory\n", cmd);
	if (fd == -1 && dir == NULL)
		g_err = 127;
	else
		g_err = 126;
	if (fd > 0)
		close(fd);
	if (dir)
		closedir(dir);
}

char	*get_redir_path(char *name)
{
	char	*pwd;
	char	*res;

	pwd = NULL;
	pwd = getcwd(NULL, 0);
	res = ft_strjoin_tripple(pwd, "/", name);
	ft_free(pwd);
	ft_free(name);
	return (res);
}
