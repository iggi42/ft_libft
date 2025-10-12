#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == '\0')
	{
		if (c == '\0')
			return ((char *) s);
		else
			return (NULL);
	}
	
	if (*s == c)
		return ((char *) s);
	else
		return ft_strchr(s + 1, c);
}
