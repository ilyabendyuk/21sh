#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

char	*get_precision(char *format, t_flags *flags)
{
	if (flags->precision == 0)
		flags->precision = ft_atoi_pft(format);
	if ((*format <= '0' || *format > '9') && (flags->precision == 0))
		flags->no_prec = 1;
	while (*format >= '0' && *format <= '9')
		format++;
	return (--format);
}

char	*get_space(char *format, t_flags *flags)
{
	if (flags->width >= 0)
		flags->width = ft_atoi_pft(format);
	while (*format >= '0' && *format <= '9')
		format++;
	return (--format);
}

void	get_4flags(char *format, t_flags *flags, va_list ptr)
{
	if (*format == '-')
		flags->minus = 1;
	else if (*format == '+')
		flags->plus = 1;
	else if (*format == ' ')
		flags->space = 1;
	else if (*format == '0')
		flags->zero = 1;
	else if (*format == '*')
	{
		if (flags->precision == 0 && flags->no_prec)
			flags->precision = va_arg(ptr, int);
		else if (flags->width == 0)
		{
			flags->width = va_arg(ptr, int);
			if (flags->width < 0)
			{
				flags->width *= -1;
				flags->minus = 1;
			}
		}
		if (flags->precision < 0)
			flags->precision = -1;
	}
}

char	*get_spec(char *f, t_flags *flags)
{
	int	i;

	i = 0;
	while (*f && i < 3 && ((*f >= 'b' && *f <= 'j') || *f == 'l'
			|| *f == 'o' || *f == 'p' || *f == 's' || *f == 'u' || *f == 'L'
			|| *f == 'x' || *f == 'X' || *f == 'r' || *f == 'D'))
	{
		flags->spec[i] = *f;
		if ((*f >= 'b' && *f <= 'g') || *f == 'i' || *f == 'o' || *f == 'p'
			|| *f == 'r' || *f == 's' || *f == 'u' || *f == 'X' || *f == 'x'
			|| *f == 'D')
		{
			f++;
			i++;
			break ;
		}
		f++;
		i++;
	}
	flags->spec[i] = '\0';
	return (f);
}
