#include <get_next_line.h>
#include <minishell.h>
#include <stdio.h>

static int	check_remember(char **remember, char **line, int *flag)
{
	char	*search_n;
	char	*remember_copy;

	*flag = 0;
	if (*remember)
	{
		search_n = ft_strchr(*remember, '\n');
		if (search_n)
		{
			*search_n = '\0';
			*line = ft_strdup(*remember);
			remember_copy = *remember;
			*remember = ft_strdup(search_n + 1);
			free(remember_copy);
			return (1);
		}
		*line = ft_strdup(*remember);
		free(*remember);
		*remember = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

static int	join_line(char **line, char *buf, char **remember)
{
	char	*delete;
	char	*was_read;
	int		read_buffer;

	read_buffer = ft_strlen_shell(buf);
	was_read = ft_strchr(buf, '\n');
	if (was_read)
	{
		buf[read_buffer - ft_strlen_shell(was_read + 1) - 1] = '\0';
		*remember = ft_strdup(was_read + 1);
		if (!(*remember))
			return (-1);
	}
	delete = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(delete);
	return (0);
}

int	check_new_line(char *remember)
{
	int	i;

	i = 0;
	if (!remember)
		return (0);
	while (remember[i])
	{
		if (remember[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	R(int len)
{
	if (g_ric == 0 && len == 0)
	{
		return (1);
	}
	else
		g_ric++;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[100 + 1];
	ssize_t		len;
	static char	*remember;
	int			flag;

	if ((check_remember(&remember, line, &flag)))
		return (1);
	while (!check_new_line(remember))
	{
		len = read(fd, buffer, 100);
		if (buffer[len - 1] != '\n')
		{
			ft_printf("  \b\b");
			if ((ft_strlen_shell(*line) == 0 && flag != 0)
				|| (ft_strlen_shell(buffer) == 0 && flag == 0)
				|| (len == 0 && !remember && g_gachi == 1) || R(len))
				return (0);
		}
		buffer[len] = '\0';
		join_line(line, buffer, &remember);
		flag++;
		if (remember)
			return (1);
	}
	return (0);
}
