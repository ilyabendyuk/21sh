/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:30:17 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 10:39:03 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_char(char const *s, char const c)
{
	char	*s1;
	char	*p;
	size_t	i;

	s1 = (char *)s;
	i = 0;
	if (!s1 || !c)
		return (0);
	if (!(p = (char *)malloc(ft_strlen(s1) + 2)))
		return (0);
	p[i++] = c;
	while (*s1 != '\0')
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	p[i] = '\0';
	return (p);
}
