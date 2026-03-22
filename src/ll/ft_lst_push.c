#include "libft_ll.h"

void	ft_lst_push(t_list **lst, void *new_el)
{
	ft_lstadd_front(lst, ft_lstnew(new_el));
}
