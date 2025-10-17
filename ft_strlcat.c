#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_l;

	dst_l = ft_strlen(dst);
	return (ft_strlcpy(dst + dst_l, src, dst_size - dst_l) + dst_l);
}
