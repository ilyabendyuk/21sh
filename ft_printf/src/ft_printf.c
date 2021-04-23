#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

void	init_struct(t_flags *flags, int fd)
{
	int	i;

	i = 0;
	flags->asterisk = 0;
	flags->grid = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->no_prec = 0;
	flags->zero_num = 0;
	flags->fd = fd;
	while (flags->spec[i++])
		flags->spec[i] = '\0';
}

int	ft_int_len(int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	init_buf(t_flags *flags)
{
	flags->buffer = 0;
	flags->count = 0;
}

int	fd_printf(int fd, const char *format, ...)
{
	va_list		ptr;
	t_flags		flags;
	char		buffer[BUFF_SIZE];

	flags.buf = (char *)buffer;
	init_buf(&flags);
	init_struct(&flags, fd);
	va_start(ptr, format);
	while (*format)
	{
		if (*format && *format == '%')
		{
			format = processing_flags((char *)++format, ptr, &flags);
			init_struct(&flags, fd);
		}
		else
			ft_putchar(*format, &flags);
		format++;
	}
	va_end(ptr);
	write(fd, flags.buf, flags.buffer);
	return (flags.count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ptr;
	t_flags		flags;
	char		buffer[BUFF_SIZE];

	flags.buf = (char *)buffer;
	init_buf(&flags);
	init_struct(&flags, 1);
	va_start(ptr, format);
	while (*format)
	{
		if (*format && *format == '%')
		{
			format = processing_flags((char *)++format, ptr, &flags);
			init_struct(&flags, 1);
		}
		else
			ft_putchar(*format, &flags);
		format++;
	}
	va_end(ptr);
	write(1, flags.buf, flags.buffer);
	return (flags.count);
}
