#include <minishell.h>

void	print_env(t_queue *env)
{
	t_queue	*e;
	t_env	*inst;

	e = env;
	while (e && ((t_env *)e))
	{
		if (e->data)
		{
			inst = (t_env *) e->data;
			if (inst && inst->value && inst->name
				&& inst->value[0] && inst->name[0])
				ft_printf("%s=%s\n", inst->name, inst->value);
		}
		e = e->next;
	}
}
