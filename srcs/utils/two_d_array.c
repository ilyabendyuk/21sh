#include <minishell.h>

int	arr_2d_len(char **arr)
{
	int		i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}

char	**realloc_2d_array(char **arr, char *line)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)ft_malloc(sizeof(char *) * (arr_2d_len(arr) + 2));
	while (arr && arr[i] != NULL)
	{
		result[i] = ft_strdup(arr[i]);
		i++;
	}
	result[i++] = ft_strdup(line);
	result[i] = NULL;
	free_2d_array(arr);
	return (result);
}

char	**sort_2d_array(char ***array)
{
	char	*tmp;
	char	**save;
	int		i;
	int		j;

	i = -1;
	save = *array;
	while (save[++i])
	{
		j = -1;
		while (save[++j] && save[j + 1])
		{
			if (ft_strcmp((const char *)save[j], (const char *)save[j + 1]) > 0)
			{
				tmp = save[j];
				save[j] = save[j + 1];
				save[j + 1] = tmp;
			}
		}
	}
	return (save);
}
