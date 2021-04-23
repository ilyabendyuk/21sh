#include <minishell.h>

static int	words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i + 1] != '\0')
			i++;
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

static char	*ft_words(char *s, char c, int j)
{
	int		count;
	char	*s1;
	int		i;
	int		count1;

	count1 = j;
	count = 0;
	while (s[count1] != c && s[count1] != '\0')
	{
		count++;
		count1++;
	}
	i = 0;
	s1 = (char *)ft_malloc(sizeof(char) * (count + 1));
	while (s[j] != c && s[j] != '\0')
	{
		s1[i] = s[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

static char	**ft_free1(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	p = (char **)ft_malloc(sizeof(char *) * (words((char *)s, c) + 1));
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0' && s[j] != c && i < words((char *)s, c))
		{
			p[i] = ft_words((char *)s, c, j);
			if (p[i] == 0)
				return (ft_free1(p, i));
			j = j + ft_strlen_shell(p[i]);
			i++;
		}
		j++;
	}
	p[i] = NULL;
	return (p);
}
