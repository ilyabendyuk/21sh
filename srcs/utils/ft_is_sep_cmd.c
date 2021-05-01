#include <minishell.h>

int	ft_is_sep_cmd(char c)
{
	return (c == '>' || c == '|' || c == '<' || c == ';');
}

int	ft_is_not_redir(char c)
{
	return (c == '|' || c == ';');
}
