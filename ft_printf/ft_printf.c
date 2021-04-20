/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:39:49 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 10:41:19 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_flag(char **str1)
{
	int		flag;
	char	*str;

	flag = 0;
	str = *str1;
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			flag = 1;
		if (*str++ == '0' && flag != 1)
			flag = 2;
	}
	*str1 = str;
	return (flag);
}

static int		ft_check_width(va_list ptr, char **str1)
{
	int		width;
	char	*str;

	width = 0;
	str = *str1;
	if (ft_isdigit(*str))
	{
		while (ft_isdigit(*str))
			width = width * 10 + (*str++ - 48);
	}
	else if (*str == '*')
	{
		width = va_arg(ptr, int);
		str++;
	}
	*str1 = str;
	return (width);
}

char			*ft_check_struct(va_list ptr, char *str, int *count)
{
	int		flag;
	int		width;
	int		i;

	flag = ft_check_flag(&str);
	width = ft_check_width(ptr, &str);
	if (width < 0)
	{
		flag = 1;
		width = width * (-1);
	}
	i = ft_check_conver(ptr, flag, width, &str);
	if (i >= 0)
		*count = *count + i;
	else
		return (0);
	return (str);
}

int				ft_printf(const char *str, ...)
{
	va_list		ptr;
	int			count;
	char		*pointer;
	ssize_t		i;

	g_fd = 1;
	count = 0;
	i = 0;
	va_start(ptr, str);
	pointer = (char *)str;
	while (*pointer != '\0')
	{
		if (*pointer != '%' && *pointer != '\0')
		{
			ft_putchar_fd(*pointer, 1);
			count++;
		}
		if (*pointer == '%')
			pointer = ft_check_struct(ptr, pointer + 1, &count);
		if (!pointer)
			return (-1);
		pointer++;
	}
	va_end(ptr);
	return (count);
}

int				fd_printf(int fd, const char *str, ...)
{
	va_list		ptr;
	int			count;
	char		*pointer;
	ssize_t		i;

	g_fd = fd;
	count = 0;
	i = 0;
	va_start(ptr, str);
	pointer = (char *)str;
	while (*pointer != '\0')
	{
		if (*pointer != '%' && *pointer != '\0')
		{
			ft_putchar_fd(*pointer, 1);
			count++;
		}
		if (*pointer == '%')
			pointer = ft_check_struct(ptr, pointer + 1, &count);
		if (!pointer)
			return (-1);
		pointer++;
	}
	va_end(ptr);
	return (count);
}
