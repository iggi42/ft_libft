#include "libft_io_opts.h"
#include "libft_iol.h"
#include "libft_ll.h"
#include "sys/types.h"
#include <unistd.h>

char	*ft_iol_read_till(t_iol *l, int fd, t_iol_breaker br)
{
	t_iol_el	*new_el;
	ssize_t		break_i;

	break_i = -1;
	while (break_i < 0)
	{
		new_el = ft_iol_el_read(fd, BUFFER_SIZE);
		if(new_el == NULL)
			break;
		break_i = br(new_el->buffer, new_el->size);
	}
	ft_lstadd_back(l, ft_lstnew(new_el));
}

// 	ft_iol_el *el
// ssize_t break_i;

// ssize_t read_code = read(fd, input_buffer, BUFFER_SIZE);
// if (read_code > 0)
// {
// 	break_i = br(input_buffer, read_code);
// 	if (break_i <= 0)
// 	{
// 	}
//     ft_iol_append(&head, (char *) input_buffer, read_code);
// }
