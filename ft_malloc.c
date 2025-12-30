#include <stdlib.h>
#include "libft_os.h"

void* ft_malloc(size_t size)
{
	void *r = malloc(size);
	if (r == NULL)
		ft_fatal();
	return (r);
}
