/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 14:01:48 by airma             #+#    #+#             */
/*   Updated: 2020/07/31 14:01:51 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_digit(char **str1)
{
	int		prec;
	char	*str;

	str = *str1;
	prec = 0;
	while (ft_isdigit(*str))
	{
		prec = prec * 10 + (*str - 48);
		str++;
	}
	*str1 = str;
	return (prec);
}

int				ft_check_precision(va_list ptr, char **str1)
{
	int			prec;
	char		*str;

	str = *str1;
	prec = -1;
	if (*str == '.')
	{
		str++;
		prec = -2;
		if (ft_isdigit(*str))
			prec = ft_digit(&str);
		else if (*str == '*')
		{
			prec = va_arg(ptr, int);
			str++;
			if (prec < 0)
				prec = -1;
		}
	}
	*str1 = str;
	return (prec);
}

int				ft_check_conver(va_list ptr, int flag, int width, char **str1)
{
	int			count;
	char		c;
	char		*str;
	int			prec;

	prec = ft_check_precision(ptr, str1);
	count = -1;
	str = *str1;
	c = **str1;
	if (c == 'c' || c == '%')
		count = ft_write_char(ptr, flag, width, c);
	else if (c == 's')
		count = ft_write_str(ptr, flag, width, prec);
	else if (c == 'p')
		count = ft_write_p(ptr, flag, width, prec);
	else if (c == 'd' || c == 'i')
		count = ft_write_int(ptr, flag, width, prec);
	else if (c == 'u')
		count = ft_write_un_int(ptr, flag, width, prec);
	else if (c == 'x')
		count = ft_write_x_lit(ptr, flag, width, prec);
	else if (c == 'X')
		count = ft_write_x_big(ptr, flag, width, prec);
	*str1 = str;
	return (count);
}
