#include <minishell.h>

int	skip_n(char *arg)
{
	if (ft_strlen(arg) < 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n')
		return (1);
	return (0);
}

void	bltn_echo(t_comand *cmd)
{
	int	i;
	int	new_line;

	new_line = 0;
	i = 1;
	if (cmd->args[i])
	{
		while (skip_n(cmd->args[i]))
			i++;
		if (i > 1)
			new_line = 1;
		while (cmd->args[i])
		{
			if (cmd->args[i + 1])
				fd_printf(1, "%s ", cmd->args[i]);
			else
				fd_printf(1, "%s", cmd->args[i]);
			i++;
		}
		if (!new_line)
			fd_printf(1, "\n");
	}
	else
		fd_printf(1, "\n");
}
