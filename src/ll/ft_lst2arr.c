
#include "libft_arr.h"
#include "libft_ll.h"

//! get all keys in a freeable, NULL terminated array
t_arr	*ft_lst2arr(t_list *head)
{
	size_t	s;
	size_t	i;
	t_arr	*result;

	i = 0;
	s = ft_lstsize(head);
	result = ft_arr_new(s);
	while (result != NULL && i < s)
	{
		result[i++] = head->content;
		head = head->next;
	}
	return (result);
}
