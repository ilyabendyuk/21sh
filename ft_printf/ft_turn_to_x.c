/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_to_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:50:38 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 16:50:40 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		check_c(int j, int x)
{
	char c;

	if (j < 10)
		c = 48 + j;
	else
	{
		if (x == 0)
			c = 87 + j;
		else
			c = 55 + j;
	}
	return (c);
}

char			*ft_turn_to_x(unsigned int n, int x)
{
	char	*p;
	int		j;
	char	c;
	char	*delete;

	p = ft_strdup1("");
	if (n == 0)
	{
		delete = p;
		p = ft_strdup1("0");
		free(delete);
	}
	while (n != 0)
	{
		j = n % 16;
		c = check_c(j, x);
		n /= 16;
		delete = p;
		p = ft_strjoin_char(p, c);
		free(delete);
	}
	return (p);
}
