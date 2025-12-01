#include "libft.h"

t_buf	*ft_buf_cat(t_buf **left, t_buf **right)
{
	size_t	i;
	t_buf	*result;
	t_byte	*src;

	i = 0;
	result = ft_buf_new((*left)->size + (*right)->size);
	if (result == NULL || result->p == NULL)
		return (NULL);
	while (i < result->size)
	{
		if (i < (*left)->size)
			src = (*left)->p + i;
		else
			src = (*right)->p + (i - (*left)->size);
		*(result->p + i++) = *src;
	}
	return (result);
}
