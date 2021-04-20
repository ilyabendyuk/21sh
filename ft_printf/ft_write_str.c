/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:45:20 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 16:45:23 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putstr_prec(char *s, int fd, int prec)
{
	int i;

	i = 0;
	if (prec == -1)
		prec = ft_strlen(s);
	if (prec == -2)
		prec = 0;
	if (s && fd)
	{
		while (s[i] != '\0' && i < prec)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int				ft_flag(int width, int count, int len)
{
	while (width - len > 0)
	{
		ft_putchar_fd(' ', g_fd);
		width--;
		count++;
	}
	return (count);
}

ssize_t			ft_write_str(va_list ptr, int flag, int width, int prec)
{
	char		*str;
	ssize_t		len;
	ssize_t		count;

	count = 0;
	str = va_arg(ptr, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (prec < len && prec >= 0)
		len = prec;
	else if (prec == -2)
		len = 0;
	if (flag == 1)
	{
		ft_putstr_prec(str, g_fd, prec);
		count = ft_flag(width, count, len);
	}
	else if (flag == 0)
	{
		count = ft_flag(width, count, len);
		ft_putstr_prec(str, g_fd, prec);
	}
	return (count + len);
}
