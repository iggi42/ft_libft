#include "libft.h"
#include <limits.h>

char	*ft_ltoa_b(long nb, const char *alphabet)
{
	char *result;
	size_t len = ft_ltoa_bl(nb, NULL, 0, alphabet);

	result = ft_str_alloc(len);
	ft_ltoa_bl(nb, result, len, alphabet);
	if (result)
		*(result + len) = '\0';
	return (result);
}
