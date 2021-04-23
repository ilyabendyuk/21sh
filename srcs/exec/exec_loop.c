#include <minishell.h>

void	execute_pipe(t_shell *shell, t_queue *cmd)
{
	g_err = 0;
	if (cmd->next)
	{
		pipe(shell->g_pipe);
		g_pid = fork();
		if (g_pid == 0)
			handle_exec(shell, cmd->data, 0);
		else
			wait_exec(shell, cmd->data);
	}
	else
	{
		exec_last_cmd(shell, cmd->data, 1);
		dup2(shell->g_save_in, 0);
		dup2(shell->g_save_out, 1);
	}
}

void	execute_comands(t_shell *shell, t_queue *cmd)
{
	shell->g_fd_in = -2;
	shell->g_fd_out = -2;
	shell->g_save_in = dup(0);
	shell->g_save_out = dup(1);
	while (cmd)
	{
		g_err = 0;
		if (!open_redirs_and_check(shell, cmd->data))
		{
			g_prev_err = g_err;
			return ;
		}
		if (((t_comand *)cmd->data)->cmd)
			execute_pipe(shell, cmd);
		g_prev_err = g_err;
		cmd = cmd->next;
	}
}
