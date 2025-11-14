#include "libft.h"

void *ft_lstfold(t_list *lst, void *acc, void *(*f)(void *, void *))
{
  if (lst == NULL)
	  return (acc);
	acc = f(acc, lst->content);
	return ft_lstfold(lst->next, acc, f);
}
