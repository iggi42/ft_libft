#include "libft.h"
#include <limits.h>
#include <unistd.h>

size_t	ft_ltoa_bl(long nb, char *target, size_t length,	const char *alphabet)
{
	size_t			len;
	size_t pre_len;
	unsigned long	n;

	char pre[3] = {0, 0, 0};

	if (nb < 0)
	{
		n = nb * -1;
		pre[0] = '-';
	}
	else
		n = nb;
	pre_len = ft_strlen(pre);
	len = ft_ultoa_bl(n, NULL, 0, alphabet);
	if ((pre_len + len) <= length && target != NULL)
	{
		ft_memcpy(target, pre, pre_len * sizeof(char));
		if (len != ft_ultoa_bl(n, target + pre_len, len, alphabet))
			return -1;
	}
	return (pre_len + len);
}
