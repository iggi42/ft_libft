#include "libft.h"

void	ft_buf_cp(t_buf *from, t_buf *to)
{
	size_t	i;

	if (from->size > to->size)
		return ;
	to->size = from->size;
	i = 0;
	while (i < to->size)
	{
		*(to->p + i) = *(from->p + i);
		i++;
	}
}
