/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:07:57 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:59 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(int width, int count, int flag, char c)
{
	if (flag == 1)
		ft_putchar_fd(c, g_fd);
	while (width > 1)
	{
		ft_putchar_fd(' ', g_fd);
		width--;
		count++;
	}
	if (flag == 0)
		ft_putchar_fd(c, g_fd);
	return (count);
}

static int		ft_flag2(int width, int count, char c)
{
	while (width > 1)
	{
		ft_putchar_fd('0', g_fd);
		width--;
		count++;
	}
	ft_putchar_fd(c, g_fd);
	return (count);
}

ssize_t			ft_write_char(va_list ptr, int flag, int width, char ch)
{
	char		c;
	ssize_t		count;

	if (ch == '%')
		c = ch;
	else
		c = va_arg(ptr, int);
	count = 0;
	if (width < 0)
	{
		flag = 1;
		width = width * (-1);
	}
	if (flag == 0 || flag == 1)
		count = ft_flag(width, count, flag, c);
	else if (flag == 2)
		count = ft_flag2(width, count, c);
	return (count + 1);
}
