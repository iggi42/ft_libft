/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:35:10 by fkruger           #+#    #+#             */
/*   Updated: 2026/04/23 13:35:11 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_cache.h"
#include "libft_ll.h"
#include "libft_mem.h"
#include <libft_io_opts.h>
#include <libft_iol.h>
#include <libft_kv.h>
#include <libft_str.h>
#include <stdbool.h>
#include <unistd.h>

static t_iol	find_rest(t_iol iol)
{
	t_iol_el	*el;
	char		*eol;
	t_iol_el	*rest;
	t_iol		res;

	if (iol == NULL || iol->content == NULL)
		return (NULL);
	el = iol->content;
	eol = ft_strnstr(iol->content, "\n", el->size);
	rest = ft_malloc(sizeof(t_iol_el));
	if (eol == NULL || rest == NULL)
		return (ft_free(rest), NULL);
	rest->size = eol - el->buffer;
	el->size -= rest->size;
	rest->free = ft_iol_free_always;
	ft_memcpy(rest->buffer, eol, rest->size);
	res = ft_lstnew(rest);
	if (res)
		return (res);
	ft_iol_el_free(rest);
	return (NULL);
}

static bool	append_block(t_iol *buffers, int fd)
{
	t_iol_el	*fresh;
	t_iol		res;

	fresh = ft_iol_el_read(fd, BUFFER_SIZE);
	res = ft_lstnew(fresh);
	if (res && fresh)
		return (ft_lstadd_back(buffers, res), true);
	ft_iol_el_free(fresh);
	return (false);
}

char	*ft_gnl(int fd)
{
	t_iol	current_line;
	t_iol	rest;
	char *res;

	current_line = fdc_pop(fd);
	rest = find_rest(current_line);
	while (rest == NULL)
	{
		if(!append_block(&current_line, fd))
			break;
		rest = find_rest(current_line);
	}

	res = ft_iol_str(current_line);
	fdc_add(fd, res);
	return (res);
}
