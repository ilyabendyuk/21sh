#include <minishell.h>

long long	ft_atoll(char *str)
{
	int			i;
	long long	num;
	long long	min;

	min = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * min);
}

void	bltn_exit(t_comand *cmd, int exit_flag)
{
	int	i;

	i = 0;
	if (exit_flag == 1)
		ft_printf("exit\n");
	if (!cmd->args[1])
		exit((int)g_prev_err);
	if ((cmd->args[1] && cmd->args[1][i] == '-') || cmd->args[1][i] == '+')
		i++;
	while (cmd->args[1] && cmd->args[1][i] >= '0' && cmd->args[1][i] <= '9')
		i++;
	if ((i == 1 && (cmd->args[i][0] == '-' || cmd->args[i][0] == '+'))
		|| cmd->args[1][i] != '\0')
	{
		fd_printf(2, "21sh: exit: %s: numeric argument required\n",
			cmd->args[1]);
		exit(255);
	}
	if (cmd->args[2])
	{
		ft_printf("21sh: exit: too many arguments\n");
		g_err = 1;
		return ;
	}
	exit((int)(ft_atoll(cmd->args[1])));
}
