#include "libft.h"

char *ft_btoa(t_byte b)
{
	return ft_ultoa_b(b, FT_ALPHABET_HEX);
}
