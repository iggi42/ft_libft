/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:34:31 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:05 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_buf.h"
#include "libft_io_opts.h"
#include "libft_mem.h"

typedef struct s_gnl
{
	t_buf		buffer;
	t_byte		cache[BUFFER_SIZE];
}				t_gnl;

static t_buf	*gnl_cache(int fd)
{
	static t_gnl	cache[1024];
	t_gnl			*my_static;

	my_static = (t_gnl *)&cache;
	my_static += (size_t)fd;
	my_static->buffer.p = (t_byte *)my_static->cache;
	return (&(my_static->buffer));
}


static char	*ft_buf_eol(t_buf *b)
{
	size_t	i;
	char	*current;

	i = 0;
	while (b != NULL && i < b->size)
	{
		current = (char *)(b->p + i++);
		if (*current == '\0' || *current == '\n')
			return (current);
	}
	return (NULL);
}

char	*ft_gnl(int fd)
{
	t_buf	*line_buf;
	t_buf	*block;
	char	*line_eol;

	line_buf = ft_buf_new(BUFFER_SIZE);
	if (line_buf == NULL)
		return (NULL);
	ft_buf_cp(gnl_cache(fd), line_buf);
	line_eol = ft_buf_eol(line_buf);
	while (line_eol == NULL)
	{
		block = ft_buf_read(fd);
		if (block == NULL)
			return (ft_buf_str(&line_buf));
		line_buf = ft_buf_cat(&line_buf, &block);
		if (line_buf == NULL)
			return (NULL);
		line_eol = ft_buf_eol(line_buf);
	}
	block = ft_buf_split(&line_buf, 1 + (t_byte *)line_eol - line_buf->p);
	gnl_cache(fd)->size = BUFFER_SIZE;
	ft_buf_cp(block, gnl_cache(fd));
	ft_buf_free(&block);
	return (ft_buf_str(&line_buf));
}
