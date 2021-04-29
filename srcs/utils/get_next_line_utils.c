#include <get_next_line.h>
#include <minishell.h>

char	*ft_strchr(const char *str, int ch)
{
	char	*str1;

	if (!str)
		return (0);
	str1 = (char *)str;
	while (*str1 != ch)
	{
		if (*str1 == '\0')
			return (0);
		str1++;
	}
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s11;
	char	*s21;
	char	*p;
	size_t	i;

	s11 = (char *)s1;
	s21 = (char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (0);
	p = (char *)ft_malloc(ft_strlen_shell(s11) + ft_strlen_shell(s21) + 1);
	while (s11[i] != '\0')
	{
		p[i] = s11[i];
		i++;
	}
	while (*s21 != '\0')
	{
		p[i] = *s21;
		i++;
		s21++;
	}
	p[i] = '\0';
	return (p);
}
