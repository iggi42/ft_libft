
#include "libft.h"

t_list	**ft_lststart(t_list *head)
{
	t_list	**result;

	result = (t_list **)malloc(sizeof(t_list *));
	*result = head;
	return (result);
}
