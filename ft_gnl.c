/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:34:31 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/03 16:28:20 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_buf.h"
#include "libft_kv.h"
#include <stdint.h>
#include <stdlib.h>

static t_buf	*gnl_cache(int fd)
{
	static t_kv_store *store;
	t_buf* result;

	if (store == NULL)
		store = ft_kv_init();
	ft_kv_get(store, (uintptr_t) fd);

	// my_static = (t_gnl *) &cache;
	// my_static += (size_t) fd;
	// my_static->buffer.p = (t_byte *) my_static->cache;
	// return (&(my_static->buffer));
	return (result);
}


char	*ft_buf_str(t_buf **b)
{
	char	*result;
	size_t	i;

	if (*b == NULL || (*b)->size == 0)
	{
		ft_buf_free(b);
		return (NULL);
	}
	result = (char *)malloc((*b)->size + 1);
	if (result == NULL)
	{
		ft_buf_free(b);
		return (NULL);
	}
	i = 0;
	while (i < (*b)->size)
	{
		*(result + i) = (char)*((*b)->p + i);
		i++;
	}
	*(result + i) = '\0';
	ft_buf_free(b);
	return (result);
}

char	*ft_buf_eol(t_buf *b)
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

void	ft_buf_free(t_buf **b)
{
	if (*b == NULL)
		return ;
	if ((*b)->p)
		free((*b)->p);
	free(*b);
	*b = NULL;
}

char	*get_next_line(int fd)
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
