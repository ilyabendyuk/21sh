#include <minishell.h>

char	*ft_strjoin_tripple(char *s1, char *s2, char *s3)
{
	char	*res;
	char	*tmp;

	res = ft_strjoin(s1, s2);
	tmp = res;
	res = ft_strjoin(res, s3);
	ft_free(tmp);
	return (res);
}
