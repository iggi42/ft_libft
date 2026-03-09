
#include "libft_arr_t.h"
#include <stddef.h>

void *ft_arr_fold(t_arr arr, t_arr_fold fold, void *acc)
{
	size_t	i;

	i = 0;
	while (*(arr + i))
		acc = fold(acc, *(arr + i++));
	return (acc);
}
