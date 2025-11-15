#include "libft.h"
#include <stdarg.h>

static size_t get_seg_size(char *template)
{
	char *seeker;

  if (*template == '\0')
    return 0;
	if (*template == '%')
		return 2;
	seeker = ft_strchr(template, '%');
	if (seeker == NULL)
		return ft_strlen(template);
	else
		return (seeker - template);
}

static t_list	*parse_template(char *template)
{
	t_list *result;
  t_iol_el *seg;
  
	if (template == NULL || *template == '\0')
		return (NULL);

	seg = (t_iol_el *)malloc(sizeof(t_iol_el));
	seg->buffer = template;
	seg->size = get_seg_size(template);
	result = ft_lstnew(seg);
	result->next = parse_template(template + seg->size);

	return (result);
}

static void replace_op_str(t_iol_el *el, char *s)
{
	el->buffer = s;
	el->size = ft_strlen(s);
}

static void replace_op(va_list args, t_iol_el *el)
{
	char type;
	
	if (el->size == 0 || *(el->buffer) != '%')
		return ;
	type = *(el->buffer + 1);
	if (type == 's')
		replace_op_str(el, va_arg(args, char *));
	else
		el->buffer = "42";
}

static void replace_ops(va_list args, t_list *io_list)
{
	if (io_list == NULL)
		return;
	replace_op(args, io_list->content);
	replace_ops(args, io_list->next);
}

int	ft_printf(const char *template, ...)
{
	va_list	args;
	t_list	*seg_list;
	int result;

	seg_list = parse_template((char *)template);
  va_start(args, template);
  replace_ops(args, seg_list);
	va_end(args);
	result = ft_iol_write(seg_list, 1);
	ft_lstclear(&seg_list, free);
	return (result);
}

int main(void)
{
	ft_printf("joas %s joa\n", "servus");
	ft_printf("[[%s]]\n", "diggi");
	ft_printf("pe%dnis\n");
	ft_printf("pe%pnis\n");
}
