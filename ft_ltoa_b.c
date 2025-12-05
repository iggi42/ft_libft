#include "libft.h"
#include <limits.h>

char	*ft_ltoa_b(long nb, const char *alphabet)
{
	char			*result;
	size_t			len;
	size_t pre_len;
	unsigned long	n;

	char pre[3] = {0, 0, 0};

	if (nb < 0)
	{
		if (nb == LONG_MIN)
		{
			n = nb / ft_strlen(alphabet);
			pre[1] = alphabet[nb % ft_strlen(alphabet)];
		}
		pre[0] = '-';
		n = nb * -1;
	}
	else
		n = nb;
	pre_len = ft_strlen(pre);
	len = ft_ulto_bl(n, NULL, 0, alphabet);
	result = (char *) malloc(pre_len + len + 1);
	if (result != NULL)
	{
		ft_memcmp(result, pre, pre_len);
		len = ft_ulto_bl(n, result + pre_len, len, alphabet);
		*(result + pre_len + len) = '\0';
	}
	return (result);
}
