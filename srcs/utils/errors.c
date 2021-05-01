#include <minishell.h>

void	errors(char *error)
{
	fd_printf(2, "%s\n", error);
	exit(1);
}

int	validation_error(t_queue *token, char *error)
{
	char	*msg;

	g_err = 258;
	if (error)
		msg = error;
	else if (!token)
		msg = "newline";
	else
		msg = token->data;
	fd_printf(2,
		   "21sh: syntax error near unexpected token '%s'\n", msg);
	return (0);
}

void	errno_err(char *cmd, int err_num, char *msg)
{
	err_num = 0;
	if (msg)
		fd_printf(2, "21sh: %s: %s\n", cmd, msg);
	else
		fd_printf(2, "21sh: %s: %s\n", cmd, "No such file or directory");
}
