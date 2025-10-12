/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:30:47 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/08 14:12:07 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft.h"
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l) != '\0')
		l++;
	return (l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_s;
	size_t	i;

	i = 0;
	src_s = ft_strlen(src) + 1;
	if (src_s > size)
		return (src_s);
	while (*(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (src_s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_b_l;

	dst_b_l = ft_strlen(dst);
	return (ft_strlcpy(dst + dst_b_l, src, size) + dst_b_l);
}

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

char	*ft_strrchr(const char *s, int c)
{
	char *found;
	char *runner;

	found = NULL;
	runner = (char *) s;
	while (*runner != '\0')
	{
		if (*runner == c)
			found = runner;
		runner++;
	}
	if (c == '\0')
		return (runner);
	else
		return (found);
}

// int		ft_strncmp(const char *s1, const char *s2, size_t n);
