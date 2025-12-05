#include "libft.h"
#include <stdarg.h>

static void	replace_op_str(t_iol_el *el, char *s)
{
	el->buffer = s;
	el->size = ft_strlen(s);
}

static void	replace_op_c(t_iol_el *el, char c)
{
	el->buffer = malloc(sizeof(char));
	if(el->buffer)
	{
		*(el->buffer) = c;
		el->size = sizeof(char);
		el->free = ft_iol_free_always;
	}
}

static void	replace_op_pointer(t_iol_el *el, void *ptr)
{
	char	*s;

	s = ft_ptoa(ptr);
	replace_op_str(el, s);
	el->free = ft_iol_free_always;
}

static void	replace_op_i(t_iol_el *el, int i)
{
	char	*s;

	s = ft_itoa(i);
	replace_op_str(el, s);
	el->free = ft_iol_free_always;
}

static void	replace_op(va_list args, t_iol_el *el)
{
	char	type;

	if (el->size == 0 || *(el->buffer) != '%')
		return ;
	type = *(el->buffer + 1);
	if (type == '%')
		el->size = sizeof(char);
	else if (type == 's')
		replace_op_str(el, va_arg(args, char *));
	else if (type == 'c')
		replace_op_c(el, (char)va_arg(args, int));
	else if (type == 'p')
		replace_op_pointer(el, (void *)va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		replace_op_i(el, (int)va_arg(args, int));
}

static void	replace_ops(va_list args, t_list *io_list)
{
	if (io_list == NULL)
		return ;
	replace_op(args, io_list->content);
	replace_ops(args, io_list->next);
}

void ft_fmt_apply(t_list **input, ...)
{
	va_list	args;

  va_start(args, input);
	replace_ops(args, *input);
	va_end(args);
}
