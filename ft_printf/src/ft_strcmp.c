#include "../includes/ft_printf.h"
#include "../includes/ft_pft.h"

int	ft_strcmp_pft(const char *src1, const char *src2)
{
	while (*src1 && *src2 && (*src1 == 'l' || *src1 == 'h'
			|| *src1 == 'j' || *src1 == 'L'))
		src1++;
	return ((unsigned char)*src1 - (unsigned char)*src2);
}
