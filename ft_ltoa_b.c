#include "libft.h"
#include <limits.h>

char	*ft_ltoa_b(long nb, const char *alphabet)
{
	char			*result;
	size_t			size;
	unsigned long	n;
	char			pre[3];

	if (nb == LONG_MIN)
	{
		n = nb / ft_strlen(alphabet);
		pre[1] = alphabet[nb % ft_strlen(alphabet)];
	}
	if (nb < 0)
	{
		pre[0] = '-';
		n = nb * -1;
	}
	else
		n = nb;
	size = ft_ulto_bl(n, NULL, 0, alphabet);
	result = (char *)malloc(size + ft_strlen(pre) + 1);
	if (result != NULL)
	{
		size = ft_ulto_bl(n, result + ft_strlen(pre), size, alphabet);
		*(result + size) = '\0';
	}
	return (result);
}
