#include <get_next_line.h>
#include <minishell.h>

static int	check_remember(char **remember, char **line)
{
	char	*search_n;
	char	*remember_copy;

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

int	check_eof(char *buff, ssize_t read_buff)
{
	if (read_buff == 1 && buff[0] == '\0')
		return (0);
	return (-2);
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

int	get_next_line(int fd, char **line)
{
	char		buffer[100 + 1];
	ssize_t		read_buffer;
	static char	*remember;

	if (fd < 0 || !line)
		return (-1);
	if ((check_remember(&remember, line)))
		return (1);
	read_buffer = 1;
	while (!check_new_line(remember))
	{
		read_buffer = read(fd, buffer, 100);
		if (buffer[read_buffer - 1] != '\n')
		{
			read_buffer = 1;
			ft_printf("  \b\b");
			break ;
		}
		buffer[read_buffer] = '\0';
		if ((join_line(line, buffer, &remember)) == -1)
			return (-1);
		if (remember)
			return (1);
	}
	return (check_eof(buffer, read_buffer));
}
