#include <minishell.h>

void	show_promt(t_shell *shell)
{
	(void)shell;
	fd_printf(1, "21sh$>");
}
