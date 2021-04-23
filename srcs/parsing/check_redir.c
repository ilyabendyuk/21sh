#include <minishell.h>

int	check_redir(char *token)
{
	int	i;

	i = 0;
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
