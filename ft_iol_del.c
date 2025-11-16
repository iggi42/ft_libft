
#include "libft.h"


static void cleanup_iol_el(void *ptr)
{
	t_iol_el *el = ptr;
	if(el != NULL && el->free != NULL)
	{
		el->free(el);
	}
	free(el);
}


void ft_iol_del(t_list **l)
{
		ft_lstclear(l, cleanup_iol_el);
}

