#include <minishell.h>

void	init_env(t_shell *shell, char **env)
{
	int		i;

	i = 0;
	shell->env = NULL;
	push_back(&(shell->env), create_env_instance("="));
	while (env[i])
	{
		push_back(&(shell->env), create_env_instance(env[i]));
		i++;
	}
}
