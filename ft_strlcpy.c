#include "./libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_s;
	size_t	i;

	i = 0;
	src_s = ft_strlen(src) + 1;
	if (src_s > size)
		return (src_s);
	while ('\0' != *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (src_s);
}
