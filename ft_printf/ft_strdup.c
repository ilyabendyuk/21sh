/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 21:25:39 by airma             #+#    #+#             */
/*   Updated: 2020/05/28 03:38:53 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup1(const char *str)
{
	char	*p;
	char	*str1;
	size_t	count;
	size_t	i;

	str1 = (char *)str;
	count = ft_strlen(str1);
	i = 0;
	if (!(p = (char *)malloc(count + 1)))
		return (0);
	while (count > i)
	{
		p[i] = str1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
