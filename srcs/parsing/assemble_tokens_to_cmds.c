#include <minishell.h>

int	exec_separator(t_shell *shell, t_queue **c, t_queue **to)
{
	t_queue	*tokens;
	t_queue	*cmd;

	cmd = *c;
	tokens = *to;
	if (cmd)
		execute_comands(shell, cmd);
	free_comands(cmd);
	cmd = NULL;
	tokens = tokens->next;
	if (!tokens)
		return (return_error(to, c, tokens, cmd));
	push_back(&cmd, init_cmd_struct());
	*c = cmd;
	*to = tokens;
	return (0);
}

void	assemble_main_cmd(t_queue *tokens, t_queue *cmd, int flag)
{
	if (flag == 0)
	{
		if (check_redir(tokens->data) > 0)
			((t_comand *)cmd->data)->cmd = ft_strdup("");
		else
			((t_comand *)cmd->data)->cmd = ft_strdup(tokens->data);
	}
}

void	assemble_redir_and_args(t_queue **to, t_queue **c)
{
	t_queue	*tokens;
	t_queue	*cmd;

	tokens = *to;
	cmd = *c;
	if (check_redir(tokens->data) > 0)
		push_redir(cmd, &tokens);
	else if (ft_strequ(tokens->data, "|") == 0)
		push_args(cmd, tokens);
	*c = cmd;
	*to = tokens;
}

int	assemble_one_cmd(t_shell *shell, t_queue **to, t_queue **c, int flag)
{
	t_queue	*tokens;
	t_queue	*cmd;

	cmd = *c;
	tokens = *to;
	if (ft_strequ(tokens->data, "|"))
	{
		while (tokens && ft_strequ(tokens->data, ";") == 0)
			tokens = push_pipe(cmd, tokens);
		if (!tokens)
			return (return_error(to, c, tokens, cmd));
	}
	if (ft_strequ(tokens->data, ";"))
	{
		flag = exec_separator(shell, &cmd, &tokens);
		if (flag == -1)
			return (return_error(to, c, tokens, cmd));
	}
	assemble_main_cmd(tokens, cmd, flag);
	assemble_redir_and_args(&tokens, &cmd);
	*c = cmd;
	*to = tokens;
	return (flag);
}

void	assemble_tokens_to_cmds(t_shell *shell)
{
	t_queue		*tokens;
	t_queue		*cmd;
	int			flag;

	flag = 0;
	tokens = shell->args;
	cmd = NULL;
	push_back(&cmd, init_cmd_struct());
	while (tokens)
	{
		flag = assemble_one_cmd(shell, &tokens, &cmd, flag);
		if (flag == -1)
			break ;
		flag++;
		tokens = tokens->next;
	}
	if (cmd)
		execute_comands(shell, cmd);
	free_comands(cmd);
}
