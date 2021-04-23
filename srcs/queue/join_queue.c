#include <minishell.h>

char	*join_queue(t_queue *args)
{
	char	*joined;
	char	*tmp;
	char	*tmp_joined;

	joined = ft_strdup("\0");
	tmp = NULL;
	tmp_joined = NULL;
	while (args)
	{
		tmp = (char *)pop_front(&args);
		tmp_joined = joined;
		joined = ft_strjoin(tmp_joined, tmp);
		ft_free(tmp_joined);
		ft_free(tmp);
	}
	return (joined);
}
