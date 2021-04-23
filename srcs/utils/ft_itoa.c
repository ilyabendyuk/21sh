#include <minishell.h>

int	len_int(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_sh(int nb)
{
	char	*res;
	long	n;
	int		i;

	n = nb;
	i = len_int(n);
	if (n == 0)
		return (ft_strdup("0\0"));
	res = (char *)ft_malloc(sizeof(char) * (i + 1));
	res[i--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[i] = (char)((n % 10) + '0');
		n = n / 10;
		i--;
	}
	return (res);
}
