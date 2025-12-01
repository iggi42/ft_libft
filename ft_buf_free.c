#include "libft.h"

void	ft_buf_free(t_buf **b)
{
	if (*b == NULL)
		return ;
	free((*b)->p);
	free(*b);
	*b = NULL;
}
