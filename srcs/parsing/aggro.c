#include "minishell.h"

int 	check_aggro(char *line)
{
	if (!(starts_with(line, ">&") || starts_with(line, "<&"))
		&& !is_number(*line))
		return (0);
	if (starts_with(line, ">&") || starts_with(line, "<&"))
		return (1);
	while (*line && is_number(*line))
		line++;
	if (starts_with(line, ">&") || starts_with(line, "<&"))
		return (1);
	return (0);
}

char	*create_aggro(char **line)
{
	char	*start;
	char	*ret;

	start = *line;
	while (is_number(**line))
		(*line)++;
	(*line) += 2;
	while (**line && !ft_is_sep_cmd(**line) && **line != ' ' && **line != '\t')
		(*line)++;
	ret = ft_strndup(start, *line - start);
	(*line)--;
	return (ret);
}
