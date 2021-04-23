#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

void	print_str(va_list ptr, t_flags *flags)
{
	const char	*str;

	str = va_arg(ptr, const char *);
	if (str != NULL)
		ft_putstr_len(str, flags, 0);
	else
		ft_putstr_len("(null)", flags, 0);
}

void	print_char(va_list ptr, t_flags *flags)
{
	if (flags->minus == 0)
	{
		if (flags->width > 0)
			print_space_char(flags->width - 1, ' ', flags);
		ft_putchar(va_arg(ptr, int), flags);
	}
	else
	{
		ft_putchar(va_arg(ptr, int), flags);
		if (flags->width > 0)
			print_space_char(flags->width - 1, ' ', flags);
	}
}
