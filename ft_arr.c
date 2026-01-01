#include "libft_arr.h"
#include "libft_mem.h"

void	**ft_arr_new(size_t size)
{
	return (ft_calloc(size + 1, sizeof(void *)));
}

size_t	ft_arr_len(void *ar)
{
	size_t	i;
	void **arr = ar;
	i = 0;
	while (*(arr + i))
		i++;
	return (i);
}
