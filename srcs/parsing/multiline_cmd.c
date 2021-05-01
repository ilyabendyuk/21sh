#include "minishell.h"

int	check_double(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			i += 2;
			continue ;
		}
		if (str[i] == '"')
			return (i);
		i++;
	}
	return (-1);
}

int	check_single(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '\'')
			return (i);
		i++;
	}
	return (-1);
}

int	check_quotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			i += 2;
			continue ;
		}
		if (str[i] == '\'')
		{
			i = check_single(str, i);
			if (i == -1)
				return (0);
		}
		if (str[i] == '"')
		{
			i = check_double(str, i);
			if (i == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
