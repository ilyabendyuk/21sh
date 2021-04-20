/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:16:48 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 13:17:33 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_atoi(const char *str)
{
	int sum;
	int min;

	sum = 0;
	min = 1;
	while (str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		sum = sum * 10 + (*str - 48);
		str++;
	}
	return (sum * min);
}

int		ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s && fd)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
