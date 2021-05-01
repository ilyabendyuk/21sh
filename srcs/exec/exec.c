#include <minishell.h>
void	exec_bin_cmd(t_shell *shell, t_comand *cmd)
{
	int		path_flag;
	char	**env;

	path_flag = get_path(shell->env, &(cmd->cmd), 0);
	if (path_flag == OPEN_ERR)
		return ;
	if (path_flag == PATH_ERR)
		return (path_err(cmd->args[0]));
	env = assemble_env(shell->env);
	g_pid = fork();
	if (g_pid)
	{
		signal(SIGINT, &sig_int);
		signal(SIGQUIT, &sig_quit);
		waitpid(g_pid, &shell->g_ret, 0);
		g_err = WEXITSTATUS(shell->g_ret);
	}
	else
	{
		shell->g_ret = execve(cmd->cmd, cmd->args, env);
		exit(shell->g_ret % 255);
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
	else if (ft_strequ(cmd->cmd, "setenv"))
		bltn_setenv(shell->env, cmd->args);
	else if (ft_strequ(cmd->cmd, "env"))
		print_env(shell->env);
	else if (ft_strequ(cmd->cmd, "unsetenv"))
		bltn_unsetenv(shell->env, cmd->args);
	else
		exec_bin_cmd(shell, cmd);
}

void	exec_last_cmd(t_shell *shell, t_comand *cmd, int exit_flag)
{
	if (shell->g_fd_in >= 0)
		dup2(shell->g_fd_in, 0);
	if (shell->g_fd_out >= 0)
		dup2(shell->g_fd_out, 1);
	execute_cmd(shell, cmd, exit_flag);
	if (shell->g_fd_in >= 0)
	{
		close(shell->g_fd_in);
		shell->g_fd_in = -2;
	}
	if (shell->g_fd_out >= 0)
	{
		close(shell->g_fd_out);
		shell->g_fd_out = -2;
	}
}

void	wait_exec(t_shell *shell, t_comand *cmd)
{
	int		err;

	(void)shell;
	(void)cmd;
	waitpid(-1, &err, WNOHANG);
	close(shell->g_pipe[1]);
	if (shell->g_fd_in == -2)
		dup2(shell->g_pipe[0], 0);
	else
		dup2(shell->g_fd_in, 0);
	close(shell->g_pipe[0]);
	g_err = WEXITSTATUS(err);
	shell->g_fd_out = -2;
	shell->g_fd_in = -2;
}

void	handle_exec(t_shell *shell, t_comand *cmd, int exit_flag)
{
	close(shell->g_pipe[0]);
	if (shell->g_fd_out == -2)
		dup2(shell->g_pipe[1], 1);
	else
		dup2(shell->g_fd_out, 1);
	close(shell->g_pipe[1]);
	execute_cmd(shell, cmd, exit_flag);
	exit((int)g_err % 256);
}
