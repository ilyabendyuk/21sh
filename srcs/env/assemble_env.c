#include <minishell.h>

char	**assemble_env(t_queue *envir)
{
	t_queue	*env;
	char	**res_env;
	t_env	*token;
	char	*env_line;

	env = envir;
	res_env = NULL;
	while (env)
	{
		token = env->data;
		if (ft_strlen_shell(token->name) > 0)
			env_line = ft_strjoin_tripple(token->name, "=", token->value);
		res_env = realloc_2d_array(res_env, env_line);
		ft_free(env_line);
		env = env->next;
	}
	return (res_env);
}
