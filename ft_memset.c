#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	t_byte	*ptr;

	i = 0;
	ptr = (t_byte *) s;
	while (i < n)
	{
		ptr[i] = (t_byte) c;
		i++;
	}
	return (s);
}
