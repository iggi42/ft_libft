#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_b_l;

	dst_b_l = ft_strlen(dst);
	return (ft_strlcpy(dst + dst_b_l, src, size) + dst_b_l);
}
