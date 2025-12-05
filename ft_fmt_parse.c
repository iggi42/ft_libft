#include "libft.h"

static size_t	get_seg_size(char *template)
{
	char	*seeker;

	if (*template == '\0')
		return (0);
	if (*template == '%')
		return (2);
	seeker = ft_strchr(template, '%');
	if (seeker == NULL)
		return (ft_strlen(template));
	else
		return (seeker - template);
}

t_list	*ft_fmt_parse(char *template)
{
	t_list		*result;
	t_iol_el	*seg;

	if (template == NULL || *template == '\0')
		return (NULL);
	seg = (t_iol_el *) malloc(sizeof(t_iol_el));
	if (seg == NULL)
		return NULL;
	seg->buffer = template;
	seg->size = get_seg_size(template);
	result = ft_lstnew(seg);
	if (result)
		result->next = ft_fmt_parse(template + seg->size);
	else
		free(seg);
	return (result);
}
