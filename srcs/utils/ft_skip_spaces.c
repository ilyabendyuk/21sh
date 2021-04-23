#include <minishell.h>

int	ft_skip_spaces(char **str)
{
	int		count;

	count = 0;
	while (*str && **str && ft_isspace(**str))
	{
		(*str)++;
		count++;
	}
	return (count);
}
