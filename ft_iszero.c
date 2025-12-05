#include "libft.h"
#include <stdbool.h>

bool ft_iszero(const void *start, const size_t size)
{
	if (size == 0)
		return true;
	t_byte rele = * (t_byte *) start;
	if (rele != 0)
		return false;
	return ft_iszero(start + 1, size - 1);
}
