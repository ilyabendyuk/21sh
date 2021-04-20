/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:30:10 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 17:30:11 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag2(long int i, int count, int width, char *str_int)
{
	ssize_t len;

	len = ft_strlen(str_int);
	if (i < 0 && i != -2147483648)
	{
		ft_putchar_fd('-', g_fd);
		count++;
		width++;
	}
	while (width - len - count > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
	}
	ft_putstr_fd(str_int, 1);
	return (count);
}

static int		ft_flag1(long int i, int prec, int width, char *str_int)
{
	ssize_t len;
	int		count;

	count = 0;
	len = ft_strlen(str_int);
	if (i < 0 && i != -2147483648)
	{
		ft_putchar_fd('-', g_fd);
		count++;
		prec++;
		width++;
	}
	while (prec - len - count > 0)
	{
		ft_putchar_fd('0', g_fd);
		count++;
	}
	ft_putstr_fd(str_int, 1);
	while (width - prec > 0)
	{
		ft_putchar_fd(' ', g_fd);
		prec++;
		count++;
	}
	return (count);
}

static int		ft_flag0(long int i, int prec, int width, char *str_int)
{
	ssize_t		len;
	int			count;

	count = 0;
	len = ft_strlen(str_int);
	while (width - prec - count > 0)
	{
		ft_putchar_fd(' ', g_fd);
		count++;
	}
	if (i < 0 && i != -2147483648)
	{
		ft_putchar_fd('-', g_fd);
		count++;
		width++;
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

ssize_t			ft_write_int(va_list ptr, int flag, int width, int prec)
{
	ssize_t		count;
	char		*str_int;
	ssize_t		len;
	long int	i;
	int			c;

	i = va_arg(ptr, int);
	c = prec;
	if (i < 0)
		width--;
	str_int = ft_itoa(i);
	if ((i == 0 && prec != -1))
		str_int = ft_strdup1("");
	len = ft_strlen(str_int);
	count = 0;
	if (prec < len)
		prec = len;
	if (flag == 2 && c < 0)
		count = ft_flag2(i, count, width, str_int);
	else if (flag == 0 || flag == 2)
		count = count + ft_flag0(i, prec, width, str_int);
	else if (flag == 1)
		count = count + ft_flag1(i, prec, width, str_int);
	free(str_int);
	return (count + len);
}
