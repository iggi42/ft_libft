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

static void always_free(t_iol_el *el)
{
	if (el != NULL)
		free(el->buffer);
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
	seg->free = NULL;
	result = ft_lstnew(seg);
	result->next = parse_template(template + seg->size);

	return (result);
}

static void replace_op_str(t_iol_el *el, char *s)
{
	el->buffer = s;
	el->size = ft_strlen(s);
}

static void replace_op_c(t_iol_el *el, char c)
{
	el->buffer = malloc(sizeof(char));
	*(el->buffer) = c;
	el->size = sizeof(char);
	el->free = always_free;
}

static void replace_op_pointer(t_iol_el *el, void *ptr)
{
	char *s = ft_ptoa(ptr);
	replace_op_str(el, s);
}

static void replace_op_i(t_iol_el *el, int i)
{
	char *s = ft_itoa(i);
	replace_op_str(el, s);
}

static void replace_op(va_list args, t_iol_el *el)
{
	char type;
	
	if (el->size == 0 || *(el->buffer) != '%')
		return ;
	type = *(el->buffer + 1);

	if (type == '%')
		el->size = sizeof(char);
	else if (type == 's')
		replace_op_str(el, va_arg(args, char *));
	else if (type == 'c')
		replace_op_c(el, (char) va_arg(args, int));
	else if (type == 'p')
		replace_op_pointer(el, (void *) va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		replace_op_i(el, (int) va_arg(args, int));
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
	ft_iol_del(&seg_list);
	return (result);
}

int main(int argc, char **argv)
{
	ft_printf("joas %c joa\n", 'c');
	ft_printf("joas %s joa\n", "servus");
	ft_printf("golden ratio: %d \n",1.61803398875);
	ft_printf("answer: %i\n", 42);
	ft_printf("unsigned negative answer: %u\n", argc);
	ft_printf("lower hex: %x\n", 0xdeadbeef);
	ft_printf("upper hex: %X\n", 0xbad1dea);
	ft_printf("pointer: %p , null: %p\n", argv, NULL);
	ft_printf("just a %%\n");
}
