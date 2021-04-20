#include <minishell.h>

char	*parse_env_var(t_queue *env, char **line)
{
	char	*start;

	if (**line == '~')
	{
		(*line)++;
		return (ft_strdup(get_env_var(env, ft_strdup("HOME"))));
	}
	(*line)++;
	start = *line;
	if (**line == '?')
	{
		(*line)++;
		return (ft_itoa_sh((int)g_prev_err));
	}
	while (**line && **line != ' ' && **line != '\0' && **line != ';'
		&& **line != '|' && **line != '>' && **line != '<' && **line != '\''
		&& **line != '\"' && **line != '\\' && **line != '$')
		(*line)++;
	return (ft_strdup(get_env_var(env, ft_strndup(start, *line - start))));
}
