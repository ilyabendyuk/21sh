#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

void	clear_buf(t_flags *flags)
{
	int	i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		flags->buf[i] = '\0';
		i++;
	}
	flags->buffer = 0;
}

void	ft_putchar(const char ch, t_flags *flags)
{
	if (flags->buffer == BUFF_SIZE)
	{
		write(flags->fd, flags->buf, flags->buffer);
		clear_buf(flags);
	}
	flags->buf[flags->buffer] = ch;
	flags->buffer++;
	flags->count++;
}

int	get_prec(t_flags *pft, const char *str)
{
	int	prec;

	if (pft->no_prec == 1 && pft->precision != 0)
		prec = ft_strlen(str);
	else
		prec = 0;
	if (pft->precision > 0 && pft->no_prec)
		prec = ft_strlen(str);
	if (pft->precision > 0 && pft->precision <= ft_strlen(str))
		prec = pft->precision;
	if ((pft->precision == 0 && pft->no_prec == 0)
		|| pft->precision > ft_strlen(str))
		prec = ft_strlen(str);
	return (prec);
}

void	ft_putstr_len(const char *str, t_flags *pft, int prec1)
{
	int		prec;
	char	c;

	if (pft->zero == 1 && !pft->minus)
		c = '0';
	else
		c = ' ';
	prec = get_prec(pft, str);
	if (pft->minus == 0)
	{
		print_space_char(pft->width - prec, c, pft);
		while (*str && prec > 0 && prec--)
			ft_putchar(*str++, pft);
	}
	if (pft->minus == 1)
	{
		prec1 = prec;
		while (*str && prec > 0 && prec--)
			ft_putchar(*str++, pft);
		print_space_char(pft->width - prec1, c, pft);
	}
}

void	ft_putstr(const char *str, t_flags *flags)
{
	while (*str)
		ft_putchar(*str++, flags);
}
