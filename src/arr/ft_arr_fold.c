
#include "libft_arr_t.h"
#include <stddef.h>

arr_t	*ft_arr_fold(arr_t ar, void *(*fold)(void *, void *), void *acc)
{
	size_t	i;
	void	**arr;

	arr = ar;
	i = 0;
	while (*(arr + i))
		acc = fold(acc, *(arr + i++));
	return (acc);
}
