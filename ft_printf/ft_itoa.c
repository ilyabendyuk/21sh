/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:48:06 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 10:39:37 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*perever(char *p, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = p[len];
		p[len] = p[i];
		p[i] = j;
		len--;
		i++;
	}
	return (p);
}

static int	len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		i;

	if (n == -2147483648)
		return (ft_strdup1("-2147483648"));
	if (!(p = (char *)malloc(len(n) + 1)))
		return (0);
	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		p[i++] = '0';
	while (n > 0)
	{
		p[i++] = (n % 10) + 48;
		n = n / 10;
	}
	p = perever(p, i - 1);
	p[i] = '\0';
	return (p);
}
