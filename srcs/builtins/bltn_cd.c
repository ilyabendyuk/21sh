#include <minishell.h>

void	set_env_cd(t_shell *shell, char *to_cd, int flag, char *oldpwd)
{
	char	*currpwd;
	char	*envoldpwd;

	envoldpwd = get_env_var(shell->env, ft_strdup("OLDPWD"));
	if (flag > -1)
	{
		if (ft_strequ(to_cd, "-"))
			ft_printf("%s\n", envoldpwd);
		currpwd = getcwd(NULL, 0);
		update_env(&shell->env, "PWD", currpwd);
		update_env(&shell->env, "OLDPWD", oldpwd);
		free(currpwd);
	}
	if (flag == -1)
	{
		g_err = 1;
		if (ft_strequ(to_cd, "-"))
			to_cd = envoldpwd;
		if (!to_cd)
			ft_printf("21sh: cd: HOME not set\n");
		else
			ft_printf("21sh: cd: %s: No such file or directory\n", to_cd);
	}
	free(oldpwd);
}

void	bltn_cd(t_shell *shell, char *to_cd)
{
	int		flag;
	char	*oldpwd;
	char	*envoldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!to_cd)
	{
		to_cd = get_env_var(shell->env, ft_strdup("HOME"));
		flag = chdir(to_cd);
	}
	else if (ft_strequ(to_cd, "-"))
	{
		envoldpwd = get_env_var(shell->env, ft_strdup("OLDPWD"));
		if (!envoldpwd)
		{
			flag = -2;
			ft_printf("21sh: cd: OLDPWD not set\n");
		}
		else
			flag = chdir(envoldpwd);
	}
	else
		flag = chdir(to_cd);
	set_env_cd(shell, to_cd, flag, oldpwd);
}
