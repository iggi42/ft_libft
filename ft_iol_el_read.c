#include "libft_iol.h"
#include <unistd.h>

t_iol_el	*ft_iol_el_read(int fd, size_t s)
{
	t_iol_el	*result;
	ssize_t		read_code;

	result = ft_iol_el_alloc(s);
	read_code = read(fd, result->buffer, s);
	if(read_code > 0)
	{
		result->size = read_code;
		return (result);
	}
	ft_iol_el_free(result);
	return NULL;
}
