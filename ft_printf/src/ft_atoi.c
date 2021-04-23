#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str && *str++)
		len++;
	return (len);
}

int	ft_atoi_pft(const char *str)
{
	unsigned long long		nbr;
	int						sign;

	sign = 1;
	nbr = 0;
	while (*str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\f' || *str == '\v'
		|| *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (unsigned long long)(nbr * 10 + *str++ - '0');
		if (nbr > 9223372036854775807 && sign == 1)
			return (-1);
		if (nbr > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(nbr * sign));
}
