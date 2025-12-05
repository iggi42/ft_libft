#include "libft.h"

char	*ft_ultoa_b(unsigned long nb, const char *alphabet)
{
	size_t	size;
	char	*result;

	size = ft_ultoa_bl(nb, NULL, 0, alphabet);
	result = ft_str_alloc(size);
	if (result != NULL)
	{
		size = ft_ultoa_bl(nb, result, size, alphabet);
		*(result + size) = '\0';
	}
	return (result);
}
