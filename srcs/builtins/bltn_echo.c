/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltn_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:21:48 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 22:00:24 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		skip_n(char *arg)
{
	if (ft_strlen(arg) < 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n')
		return (1);
	return (0);
}

void	bltn_echo(t_comand *cmd)
{
	int i;
	int new_line;

	new_line = 0;
	i = 1;
	if (cmd->args[i])
	{
		while (skip_n(cmd->args[i]))
			i++;
		(i > 1) ? new_line = 1 : 0;
		while (cmd->args[i])
		{
			if (cmd->args[i + 1])
				fd_printf(1, "%s ", cmd->args[i]);
			else
				fd_printf(1, "%s", cmd->args[i]);
			i++;
		}
		(!new_line) ? fd_printf(1, "\n") : 0;
	}
	else
		fd_printf(1, "\n");
}
