#include "libft.h"
#include <unistd.h>

void ft_iol_pp(t_list *l)
{
	if (l == NULL)
	  return;
  ft_iol_pp_el((t_iol_el *) l->content);
	ft_iol_pp(l->next);
}
