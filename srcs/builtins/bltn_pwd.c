#include <minishell.h>

void	bltn_pwd(void)
{
	char	path[1024];

	getcwd(path, 1024);
	fd_printf(1, "%s\n", path);
}
