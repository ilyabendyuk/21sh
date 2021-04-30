#include <minishell.h>

void	init_globals(void)
{
	g_pid1 = 0;
	g_pid = 0;
	g_err = 0;
	g_sigquit = 0;
	g_sigint = 0;
}

t_comand	*init_cmd_struct(void)
{
	t_comand	*cmd;

	cmd = (t_comand *)ft_malloc(sizeof(t_comand));
	cmd->cmd = NULL;
	cmd->redir = NULL;
	cmd->args = NULL;
	return (cmd);
}
