#include "libft.h"

void	ft_iol_free_always(t_iol_el *el)
{
	if (el != NULL)
		free(el->buffer);
}
