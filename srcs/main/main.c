#include <minishell.h>
#include <get_next_line.h>
#include <stdio.h>

void 	check_multiline(char **line)
{
	char	*acct_line;
	char	*tmp_line;
	char	*prev_line;

	g_gachi = 1;
	tmp_line = 0;
	acct_line = *line;
	while (!check_quotes(acct_line))
	{
		ft_printf("> ");
		get_next_line(0, &tmp_line);
		prev_line = ft_strjoin_tripple(acct_line, "\n", tmp_line);
		tmp_line = ft_free(tmp_line);
		acct_line = ft_free(acct_line);
		acct_line = prev_line;
	}
	*line = acct_line;
}

void	parse_and_exec(t_shell *shell, char *line)
{
	int		ret;

	ret = get_next_line(0, &line);
	if (ret > 0)
	{
		check_multiline(&line);
		parse_comands(shell, line);
		if (validate_tokens(shell->args, 0) == 0)
		{
			line = ft_free(line);
			free_tokens(shell->args);
			show_promt(shell);
			return ;
		}
		assemble_tokens_to_cmds(shell);
		free_tokens(shell->args);
		line = ft_free(line);
		show_promt(shell);
	}
	if (ret == 0)
	{
		ft_printf("exit\n");
		exit(g_err);
	}
	line = ft_free(line);
}

void	minishell(t_shell *shell)
{
	char	*line;

	line = NULL;
	show_promt(shell);
	while (21)
	{
		init_globals();
		g_gachi = 0;
		signal(SIGQUIT, &sig_quit);
		signal(SIGINT, &sig_int);
		line = NULL;
		parse_and_exec(shell, line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	g_err = 0;
	g_prev_err = 0;
	shell.g_ret = 0;
	shell.args = NULL;
	g_ric = 0;
	init_env(&shell, env);
	minishell(&shell);
	exit(0);
}
