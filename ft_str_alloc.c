#include "libft.h"
#include <unistd.h>

char *ft_str_alloc(size_t len)
{
	char *result = (char *) malloc((len + 1) * sizeof(char));
	ft_memset(result, '#', len);
	if (result)
		*(result + len) = '\0';
	return result;
}
