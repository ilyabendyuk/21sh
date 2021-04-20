#include <minishell.h>

t_env	*create_env_instance(char *inst)
{
	t_env	*res;
	int		i;

	i = 0;
	res = (t_env *)ft_malloc(sizeof(t_env));
	while (inst[i] && inst[i] != '=')
		i++;
	res->name = ft_strndup(inst, i);
	i++;
	res->value = ft_strdup(inst + i);
	return (res);
}
