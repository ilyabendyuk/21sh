#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

static void	processing_printf(va_list ptr, t_flags *p)
{
	if (ft_strcmp_pft(p->spec, "c") == 0)
		print_char(ptr, p);
	else if (ft_strcmp_pft(p->spec, "s") == 0)
		print_str(ptr, p);
}

void	print_space_char(int len, char ch, t_flags *flags)
{
	while (len > 0 && len--)
		ft_putchar(ch, flags);
}

void	print_util(t_flags *flags)
{
	char	c;

	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	else
		c = ' ';
	if (flags->minus == 0)
	{
		print_space_char(flags->width - 1, c, flags);
		ft_putchar('%', flags);
	}
	if (flags->minus == 1)
	{
		ft_putchar('%', flags);
		print_space_char(flags->width - 1, c, flags);
	}
}

char	*processing_flags(char *f, va_list ptr, t_flags *flags)
{
	while (*f)
	{
		if (*f == '.')
			f = get_precision(++f, flags);
		else if (*f >= '1' && *f <= '9')
			f = get_space(f, flags);
		else if (*f && ((*f >= 'b' && *f <= 'j') || *f == 'l' || *f == 'o'
				|| *f == 'p' || *f == 's' || *f == 'u' || *f == 'L' || *f == 'x'
				|| *f == 'X' || *f == 'U' || *f == 'r' || *f == 'D'))
		{
			f = get_spec(f, flags);
			processing_printf(ptr, flags);
			return (--f);
		}
		else if (*f == '%')
		{
			print_util(flags);
			return (f);
		}
		else
			get_4flags(f, flags, ptr);
		if (*f)
			f++;
	}
	return (--f);
}
