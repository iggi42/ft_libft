#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *template, ...)
{
	t_list	*seg_list;
	int		result;

	seg_list = ft_fmt_parse((char *) template);
	result = ft_iol_write(seg_list, 1);
	ft_iol_del(&seg_list);
	return (result);
}
