#include "minishell.h"

int	starts_with(char *line, char *to_find)
{
	if (ft_strlen_shell(line) < ft_strlen_shell(to_find))
		return (0);
	while (*line && *to_find)
	{
		if (*line != *to_find)
			return (0);
		line++;
		to_find++;
	}
	return (1);
}
