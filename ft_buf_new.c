#include "libft.h"
#include <stdio.h>

t_buf	*ft_buf_new(size_t size)
{
	t_buf	*result;

	result = (t_buf *) malloc(sizeof(t_buf));
	if (result == NULL)
		return (NULL);
	result->size = size;
	result->p = (t_byte *) malloc(size * sizeof(t_byte));
	if (result->p == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
