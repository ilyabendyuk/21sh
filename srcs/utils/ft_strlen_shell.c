#include <minishell.h>

int	ft_strlen_shell(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
