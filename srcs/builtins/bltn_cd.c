/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:21:36 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		update_env(&shell->env->head, "PWD", currpwd);
		update_env(&shell->env->head, "OLDPWD", oldpwd);
		free(currpwd);
	}
	if (flag == -1)
	{
		g_err = 1;
		if (ft_strequ(to_cd, "-"))
			to_cd = envoldpwd;
		if (!to_cd)
			ft_printf("minishell: cd: HOME not set\n");
		else
			ft_printf("minishell: cd: %s: No such file or directory\n", to_cd);
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
			ft_printf("minishell: cd: OLDPWD not set\n");
		}
		else
			flag = chdir(envoldpwd);
	}
	else
		flag = chdir(to_cd);
	set_env_cd(shell, to_cd, flag, oldpwd);
}
