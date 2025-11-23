#include "libft.h"

static char	*make_str(unsigned long nb, size_t base)
{
	size_t n;
	n = 1;
	while (nb > ft_pow(base, n))
		n++;
	return (ft_calloc(n, sizeof(char)));
}

static void	ft_ultoa_b_do(unsigned long nb, const char *alphabet, char *target,
		t_byte base)
{
	unsigned long	nxt_nb;

	nxt_nb = nb / base;
	if (nxt_nb > base)
		ft_ultoa_b_do(nxt_nb, alphabet, target + 1, base);
	*target = alphabet[nb % base];
}

char	*ft_ultoa_b(unsigned long nb, const char *alphabet)
{
	t_byte	base;
	char	*result;

	base = ft_strlen(alphabet);
	result = make_str(base);
	ft_ultoa_b_do(nb, alphabet, result, base);
	return (result);
}

