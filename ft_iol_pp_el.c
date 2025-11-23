#include "libft.h"

void ft_iol_pp_el(t_iol_el *el)
{
	if (el == NULL)
		ft_printf("[NULL] io element\n");
	else
		ft_printf("%ld : %s\n", el->size, el->buffer);
}

