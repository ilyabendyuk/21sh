/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:47:35 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 17:47:37 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_turn_to_x1(long int n)
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
		if (j < 10)
			c = 48 + j;
		else
			c = 87 + j;
		n /= 16;
		delete = p;
		p = ft_strjoin_char(p, c);
		free(delete);
	}
	return (p);
}

static int		ft_flag1(int width, int count, char *str_int)
{
	ssize_t		len;

	len = ft_strlen(str_int);
	ft_putstr_fd("0x", g_fd);
	ft_putstr_fd(str_int, g_fd);
	while (width - len - count - 2 > 0)
	{
		ft_putchar_fd(' ', g_fd);
		count++;
	}
	return (count);
}

static int		ft_flag0(int width, int count, char *str_int)
{
	ssize_t		len;

	len = ft_strlen(str_int);
	while (width - len - 2 - count > 0)
	{
		ft_putchar_fd(' ', g_fd);
		count++;
	}
	ft_putstr_fd("0x", g_fd);
	ft_putstr_fd(str_int, g_fd);
	return (count);
}

static int		ft_flag2(int width, int count, char *str_int)
{
	ssize_t		len;

	len = ft_strlen(str_int);
	ft_putstr_fd("0x", g_fd);
	while (width - len - count - 2 > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
	}
	ft_putstr_fd(str_int, g_fd);
	return (count);
}

ssize_t			ft_write_p(va_list ptr, int flag, int width, int prec)
{
	ssize_t		count;
	intptr_t	i;
	ssize_t		len;
	char		*str_int;

	i = va_arg(ptr, intptr_t);
	if (prec == -2)
		str_int = ft_strdup1("");
	else if (i == 0)
		str_int = ft_strdup1("0");
	else
		str_int = ft_turn_to_x1(i);
	count = 0;
	len = ft_strlen(str_int);
	if (flag == 0)
		count = ft_flag0(width, count, str_int);
	else if (flag == 1)
		count = ft_flag1(width, count, str_int);
	else if (flag == 2)
		count = ft_flag2(width, count, str_int);
	free(str_int);
	return (count + len + 2);
}
