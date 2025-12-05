#include "libft.h"

t_iol_el	*ft_iol_el_alloc(size_t size)
{
	t_iol_el	*seg;
	char *start;

	seg = (t_iol_el *) malloc(sizeof(t_iol_el));
	start = (char *) malloc(size);
	if (seg == NULL || start == NULL)
	{
		ft_free(&seg, &start);
		return (NULL);
	}
	seg->buffer = start;
	seg->size = size;
	seg->free = ft_iol_free_always;
	return (seg);
}
