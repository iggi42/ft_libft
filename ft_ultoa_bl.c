#include "libft.h"

size_t	ft_ultoa_bl(unsigned long nb, char *target, size_t length,
		const char *alphabet)
{
	size_t				alphabet_size;
	unsigned long long	largest_base;
	size_t				digit_i;
	size_t				result_size;

	alphabet_size = ft_strlen(alphabet);
	largest_base = alphabet_size;
	digit_i = 1;
	while (nb > largest_base)
	{
		largest_base *= alphabet_size;
		digit_i++;
	}
	result_size = digit_i;
	if (digit_i <= length)
	{
		while (digit_i-- > 0)
		{
			largest_base /= alphabet_size;
			*(target++) = alphabet[(nb / largest_base) % alphabet_size];
		}
	}
	return (result_size);
}
