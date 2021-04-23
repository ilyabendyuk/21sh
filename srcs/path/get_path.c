#include <minishell.h>

char	*join_decreased_path(char *pwd, char *path, int l)
{
	int		len_pwd;
	int		flag_path;
	int		save;

	flag_path = l;
	len_pwd = ft_strlen_shell(pwd) - 1;
	while (pwd[len_pwd])
	{
		if (pwd[len_pwd] == '/')
		{
			save = len_pwd;
			flag_path -= 3;
		}
		if (flag_path == 0)
			return (ft_strjoin(ft_strndup(pwd, save + 1), ft_strdup(path + l)));
		len_pwd--;
	}
	if (flag_path != 0 || ((path[l] == '.' && path[l + 1] == '.'
				&& path[l + 2] != '/')))
		return (NULL);
	return (ft_strjoin(ft_strndup(pwd, save + 1), ft_strdup(path + l)));
}

char	*get_relative_path(char *path)
{
	char	*pwd;
	char	*res_path;

	pwd = getcwd(NULL, 10);
	if (!pwd)
		return (NULL);
	if (path[0] == '.' && path[1] == '.')
		res_path = join_decreased_path(pwd, path, count_decrease_lvl(path));
	else if (path[0] == '.' && path[1] == '/')
		res_path = ft_strjoin(pwd, path + 1);
	else
		res_path = ft_strjoin_tripple(pwd, "/", path);
	ft_free(pwd);
	ft_free(path);
	return (res_path);
}

char	*get_env_path(t_queue *env, char *cmd)
{
	char	*home;
	char	**path;
	int		i;

	home = ft_strdup(get_env_var(env, ft_strdup("PATH")));
	path = ft_split(home, ':');
	ft_free(home);
	i = 0;
	while (path && path[i])
	{
		home = ft_strjoin_tripple(path[i], "/", cmd);
		if (open(home, O_RDONLY) != -1)
		{
			ft_free(cmd);
			free_2d_array(path);
			return (home);
		}
		ft_free(home);
		i++;
	}
	free_2d_array(path);
	return (cmd);
}

int	check_path(char *path, int path_flag, int redir_flag)
{
	int			fd;
	struct stat	st;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		if (redir_flag == 1)
			return (1);
		g_err = 127;
		if (path_flag == RELATIVE_PATH)
			errno_err(path, 0, NULL);
		else
			errno_err(path, 0, "command not found");
		return (OPEN_ERR);
	}
	close(fd);
	if (!stat(path, &st))
	{
		if (S_ISREG(st.st_mode) && st.st_mode & 0111)
			return (path_flag);
	}
	return (PATH_ERR);
}

int	get_path(t_queue *env, char **cmd, int redir_flag)
{
	int		path_flag;

	if (*cmd && *cmd[0] == '/')
		path_flag = RELATIVE_PATH;
	else if (ft_strchr(*cmd, '/'))
	{
		*cmd = get_relative_path(*cmd);
		path_flag = RELATIVE_PATH;
	}
	else
	{
		if (redir_flag == 1)
			*cmd = get_redir_path(*cmd);
		else
			*cmd = get_env_path(env, *cmd);
		path_flag = ENV_PATH;
	}
	return (check_path(*cmd, path_flag, redir_flag));
}
