/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_un_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:56:45 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 16:56:47 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag1(int width, int prec, int count, char *str_int)
{
	ssize_t len;

	len = ft_strlen(str_int);
	while (prec - len - count > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
	}
	ft_putstr_fd(str_int, g_fd);
	while (width - prec > 0)
	{
		ft_putchar_fd(' ', g_fd);
		prec++;
		count++;
	}
	return (count);
}

static int		ft_flag0(int width, int prec, int count, char *str_int)
{
	ssize_t len;

	len = ft_strlen(str_int);
	while (width - prec - count > 0)
	{
		ft_putchar_fd(' ', g_fd);
		count++;
	}
	while (prec - len > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
		prec--;
	}
	ft_putstr_fd(str_int, g_fd);
	return (count);
}

static int		ft_flag2(int width, int count, char *str_int)
{
	ssize_t len;

	len = ft_strlen(str_int);
	while (width - len - count > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
	}
	ft_putstr_fd(str_int, g_fd);
	return (count);
}

ssize_t			ft_write_un_int(va_list ptr, int flag, int width, int prec)
{
	ssize_t		count;
	char		*str_int;
	ssize_t		len;
	int			i;
	int			c;

	i = va_arg(ptr, unsigned int);
	c = prec;
	str_int = ft_un_itoa(i);
	if ((i == 0 && prec >= 0) || prec == -2)
		str_int = ft_strdup1("");
	len = ft_strlen(str_int);
	count = 0;
	if (prec < len)
		prec = len;
	if (flag == 2 && c < 0)
		count = ft_flag2(width, count, str_int);
	else if (flag == 0 || flag == 2)
		count = ft_flag0(width, prec, count, str_int);
	else if (flag == 1)
		count = ft_flag1(width, prec, count, str_int);
	free(str_int);
	return (count + len);
}
