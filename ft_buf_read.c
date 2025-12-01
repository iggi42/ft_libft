#include "libft.h"
#include <unistd.h>

t_buf	*ft_buf_read(int fd)
{
	t_byte	*p;
	int		read_result;
	t_buf	*result;

	p = (t_byte *)malloc(BUFFER_SIZE);
	if (p == NULL)
		return (NULL);
	read_result = read(fd, p, BUFFER_SIZE);
	if (read_result <= 0)
	{
		free(p);
		return (NULL);
	}
	result = (t_buf *)malloc(sizeof(t_buf));
	if (result == NULL)
	{
		free(p);
		return (NULL);
	}
	result->size = read_result;
	result->p = p;
	return (result);
}
