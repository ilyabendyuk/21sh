#include <minishell.h>

static char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_redir(char *token)
{
	int	i;

	i = 0;
	if (ft_strstr(token, "<&") > 0 || ft_strstr(token, ">&") > 0) // TODO check
		return (1);
	while (token && (*token == '>' || *token == '<'))
	{
		i++;
		token++;
	}
	if (i == 0)
		return (0);
	if (*token != '\0')
		return (0);
	return (1);
}
