#include <minishell.h>

void	update_env(t_queue **env, char *name, char *val)
{
	t_env	*env_inst;
	t_queue	*tmp;
	char	*tmp_name;

	tmp = *env;
	if (!(get_env_var(tmp, ft_strdup(name))))
	{
		tmp_name = ft_strjoin_tripple(name, "=", val);
		push_back(&tmp, create_env_instance(tmp_name));
		free(tmp_name);
	}
	else
	{
		while (tmp)
		{
			env_inst = tmp->data;
			if (ft_strequ(name, env_inst->name))
			{
				env_inst->value = ft_free(env_inst->value);
				env_inst->value = ft_strdup(val);
			}
			tmp = tmp->next;
		}
	}
}
