#include <minishell.h>

int	return_error(t_queue **c1, t_queue **q1, t_queue *c, t_queue *q)
{
	*c1 = c;
	*q1 = q;
	return (-1);
}
