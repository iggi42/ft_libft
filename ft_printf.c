#include "libft.h"
#include <stdarg.h>

typedef struct s_iol_el
{
	t_byte		*buffer;
	size_t		size;
}				t_iol_el;

typedef struct s_iol_fld_acc
{
	char		*runner;
	t_list		**io_list;
}				t_ifa;

// return rest of the template
// @param op_start points to where an operator '%' is.
static char	*add_op(t_list **io_list, char *op_start)
{
	t_list	*new_lnk;

	new_lnk = ft_lstnew(op_start);
	ft_lstadd_back(io_list, new_lnk);
	return (op_start + 2);
}

static t_ifa	*ft_ifa(const char *tmpl)
{
	t_ifa	*result;

	result = (t_ifa *)malloc(sizeof(t_ifa));
	result->runner = (char *)tmpl;
	result->io_list = ft_lststart(NULL);
	return (result);
}

static t_iol_el	*ft_iol_new(t_byte *buffer, size_t size)
{
	t_iol_el	*result;

	result = (t_iol_el *)malloc(sizeof(t_iol_el));
	result->buffer = buffer;
	result->size = size;
	return (result);
}

static t_list	*fold_template(char *template)
{
	if (template == NULL || *template == '\0')
		return (NULL);
	return (io_list);
}

int	ft_printf(const char *template, ...)
{
	va_list	args;
	t_list	**io_list;

	io_list = fold_template((char *)template);
	va_start(args, template);
	while (found != NULL)
	{
		found = add_op(io_list, found);
	}
	return (size);
}
