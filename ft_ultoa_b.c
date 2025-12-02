#include "libft.h"

char	*ft_ultoa_b(unsigned long nb, const char *alphabet)
{
	size_t	size;
	char	*result;

	size = ft_ulto_bl(nb, NULL, 0, alphabet);
	result = (char *)malloc(size + 1);
	if (result != NULL)
	{
		size = ft_ulto_bl(nb, result, size, alphabet);
		*(result + size) = '\0';
	}
	return (result);
}
