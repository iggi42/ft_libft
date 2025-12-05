#include "libft.h"
#include <unistd.h>

int ft_iol_write(t_list *l, int fd)
{
	t_iol_el *el;
	int r;
	int rr;

	if(l == NULL)
		return 0;
	el = (t_iol_el *) l->content;
	r = write(fd, el->buffer, el->size);
	if (r == -1)
		return -1;
	rr = ft_iol_write(l->next, fd);
	if (rr == -1)
		return -1;
	return (r + rr);
}
