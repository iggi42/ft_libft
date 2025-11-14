#include "libft.h"
#include <stdarg.h>

typedef struct s_iol_el
{
	char *buffer;
	size_t		size;
}				t_iol_el;

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

#include <unistd.h>
static int ft_iol_write(t_list *l, int fd)
{
	t_iol_el *el;
	int r;
	int rr;

	if(l == NULL)
		return -1;
	el = (t_iol_el *) l->content;
	r = write(fd, el->buffer, el->size);
	if (r == -1)
		return -1;
	rr = ft_iol_write(l->next, fd);
	if (rr == -1)
		return -1;
	return (r + rr);
}

// DEBUG function
#include <stdio.h>
static void ft_iol_pp_el(t_iol_el *el)
{
	if (el == NULL)
		printf("[NULL] io element");
	else
		printf("%ld : %s\n", el->size, el->buffer);
}

static void ft_iol_pp(t_list *l)
{
	t_iol_el *el;
	int r;

	if (l == NULL)
	{
		write(1, "[NULL]\n", 7);
	  return;
	}
  ft_iol_pp_el((t_iol_el *) l->content);
	ft_iol_pp(l->next);
}

static void escape_el(t_iol_el *el)
{
	
}

static void make_str(t_iol_el *el, char* str)
{
	
}

static void make_char(t_iol_el *el, char c)
{
	
}

void replace_ops(t_list *l)
{
	
}

int	ft_printf(const char *template, ...)
{
	va_list	args;
	t_list	*seg_list;
	t_list *lel;
	t_iol_el *io_el;

	seg_list = parse_template((char *)template);
	lel = seg_list;
  va_start(args, template);
  replace_ops(seg_list, args);
	va_end(args);
	//ft_iol_pp(seg_list);
	return ft_iol_write(seg_list, 1);
}

int main(void)
{
	ft_printf("joasj%sjoa\n");
	ft_printf("[[%s]]\n");
	ft_printf("pe%dnis\n");
	ft_printf("pe%pnis\n");
}
