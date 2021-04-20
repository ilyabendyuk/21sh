#include <minishell.h>

void	print_env(t_queue *env)
{
	t_queue	*e;
	t_env	*inst;

	e = env;
	while (e)
	{
		inst = (t_env *)e->data;
		if (inst->value[0])
			ft_printf("%s=%s\n", inst->name, inst->value);
		e = e->next;
	}
}
