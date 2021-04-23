#include <minishell.h>

void	*ft_malloc(size_t bytes)
{
	void	*mem;

	mem = NULL;
	mem = (void *)malloc(bytes);
	if (!mem)
		errors(MEM_ERROR);
	return (mem);
}
