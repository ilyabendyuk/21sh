#include <minishell.h>

void	exec_bin_cmd(t_shell *shell, t_comand *cmd)
{
	int		path_flag;
	char	**env;

	path_flag = get_path(shell->env->head, &(cmd->cmd), 0);
	if (path_flag == OPEN_ERR)
		return ;
	if (path_flag == PATH_ERR)
		return (path_err(cmd->args[0]));
	env = assemble_env(shell->env->head);
	g_pid = fork();
	if (g_pid)
	{
		signal(SIGINT, &sig_int);
		signal(SIGQUIT, &sig_quit);
		waitpid(g_pid, &g_ret, WUNTRACED);
		g_err = WEXITSTATUS(g_ret);
	}
	else
	{
		g_ret = execve(cmd->cmd, cmd->args, env);
		exit(g_ret % 255);
	}
	free_2d_array(env);
}

void	execute_cmd(t_shell *shell, t_comand *cmd, int exit_flag)
{
	if (!cmd->cmd[0])
		return ;
	if (ft_strequ(cmd->cmd, "echo"))
		bltn_echo(cmd);
	else if (ft_strequ(cmd->cmd, "pwd"))
		bltn_pwd();
	else if (ft_strequ(cmd->cmd, "cd"))
		bltn_cd(shell, cmd->args[1]);
	else if (ft_strequ(cmd->cmd, "exit"))
		bltn_exit(cmd, exit_flag);
	else if (ft_strequ(cmd->cmd, "export"))
		bltn_export(shell->env->head, cmd->args);
	else if (ft_strequ(cmd->cmd, "env"))
		print_env(shell->env->head);
	else if (ft_strequ(cmd->cmd, "unset"))
		bltn_unset(shell->env->head, cmd->args);
	else
		exec_bin_cmd(shell, cmd);
}

void	exec_last_cmd(t_shell *shell, t_comand *cmd, int exit_flag)
{
	int		save_fd[2];

	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	if (g_fd_in >= 0)
		dup2(g_fd_in, 0);
	if (g_fd_out >= 0)
		dup2(g_fd_out, 1);
	execute_cmd(shell, cmd, exit_flag);
	if (g_fd_in >= 0)
	{
		close(g_fd_in);
		g_fd_in = -2;
		dup2(save_fd[0], 0);
	}
	if (g_fd_out >= 0)
	{
		close(g_fd_out);
		g_fd_out = -2;
		dup2(save_fd[1], 1);
	}
}

void	wait_exec(t_shell *shell, t_comand *cmd)
{
	int		err;

	(void)shell;
	(void)cmd;
	waitpid(-1, &err, 0);
	close(g_pipe[1]);
	if (g_fd_in == -2)
		dup2(g_pipe[0], 0);
	else
		dup2(g_fd_in, 0);
	close(g_pipe[0]);
	g_err = WEXITSTATUS(err);
	g_fd_out = -2;
	g_fd_in = -2;
}

void	handle_exec(t_shell *shell, t_comand *cmd, int exit_flag)
{
	close(g_pipe[0]);
	if (g_fd_out == -2)
		dup2(g_pipe[1], 1);
	else
		dup2(g_fd_out, 1);
	close(g_pipe[1]);
	execute_cmd(shell, cmd, exit_flag);
	exit((int)g_err % 256);
}
