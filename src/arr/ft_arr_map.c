
#include "libft_arr.h"

t_arr	*ft_arr_map(t_arr input, t_arr_scal apply)
{
	t_arr	*result;
	size_t	size;
	size_t	i;

	size = ft_arr_len(input);
	result = ft_arr_new(size);
	i = 0;
	while (*(input + i))
	{
		*(result + i) = apply(*(input + i));
		i++;
	}
	return (result);
}
