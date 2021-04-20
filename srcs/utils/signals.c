/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:55 by airma             #+#    #+#             */
/*   Updated: 2021/01/13 23:39:12 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	sig_int(int code)
{
	code = 0;
	if (g_pid == 0)
	{
		fd_printf(2, "\b\b  \n");
		fd_printf(2, "minishell$>");
		g_err = 1;
	}
	else
	{
		kill(g_pid, g_err);
		fd_printf(2, "\n");
		g_err = 130;
	}
	g_sigint = 1;
}

void	sig_quit(int code)
{
	char	*err;

	err = ft_itoa_sh(code);
	if (g_pid != 0)
	{
		fd_printf(2, "Quit: %s\n", err);
		g_err = 131;
		g_sigquit = 1;
	}
	else
		fd_printf(2, "\b\b  \b\b");
	free(err);
}
