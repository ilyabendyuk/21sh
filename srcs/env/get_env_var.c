#include <minishell.h>

char	*get_env_var(t_queue *envir, char *name)
{
	t_queue	*env;

	env = envir;
	while (env)
	{
		if (ft_strequ(((t_env *)env->data)->name, name))
		{
			ft_free(name);
			return (((t_env *)env->data)->value);
		}
		env = env->next;
	}
	ft_free(name);
	return (NULL);
}
