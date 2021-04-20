/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:22:33 by airma             #+#    #+#             */
/*   Updated: 2021/01/15 00:29:08 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <get_next_line.h>

void	parse_and_exec(t_shell *shell, char *line)
{
	int		ret;

	if ((ret = get_next_line(0, &line)) > 0)
	{
		parse_comands(shell, line);
		if (validate_tokens(shell->args) == 0)
		{
			(line) ? free(line) : NULL;
			line = NULL;
			free_tokens(shell->args);
			show_promt(shell);
			return ;
		}
		assemble_tokens_to_cmds(shell);
		free_tokens(shell->args);
		(line) ? free(line) : NULL;
		line = NULL;
		show_promt(shell);
	}
	if (ret == 0)
	{
		ft_printf("exit\n");
		exit(g_err);
	}
	(line) ? free(line) : NULL;
}

void	minishell(t_shell *shell)
{
	char	*line;

	line = NULL;
	show_promt(shell);
	while (21)
	{
		init_globals();
		signal(SIGQUIT, &sig_quit);
		signal(SIGINT, &sig_int);
		line = NULL;
		parse_and_exec(shell, line);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	g_err = 0;
	g_prev_err = 0;
	g_ret = 0;
	shell.args = NULL;
	init_env(&shell, env);
	minishell(&shell);
	exit(0);
}
