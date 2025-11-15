#include "libft.h"

// DEBUG function
#include <stdio.h>

void ft_iol_pp_el(t_iol_el *el)
{
	if (el == NULL)
		printf("[NULL] io element");
	else
		printf("%ld : %s\n", el->size, el->buffer);
}

