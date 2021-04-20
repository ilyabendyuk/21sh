/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:23:44 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <minishell.h>

char	*ft_strchr(const char *str, int ch)
{
	char *str1;

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
