/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:14 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	errors(char *error)
{
	fd_printf(2, "%s\n", error);
	exit(1);
}

int		validation_error(t_queue *token, char *error)
{
	char *msg;

	g_err = 258;
	if (error)
		msg = error;
	else if (!token)
		msg = "newline";
	else
		msg = token->data;
	fd_printf(2,
			"minishell: syntax error near unexpected token '%s'\n", msg);
	return (0);
}

void	errno_err(char *cmd, int err_num, char *msg)
{
	if (msg)
		fd_printf(2, "minishell: %s: %s\n", cmd, msg);
	else
		fd_printf(2, "minishell: %s: %s\n", cmd, strerror(err_num));
}
