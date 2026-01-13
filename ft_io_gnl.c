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

#include "libft_iol.h"
#include "libft_kv.h"
#include "libft_mem.h"
#include "sys/types.h"
#include <stdlib.h>

// return -1 on break not found
// else returns the index of the break found
typedef ssize_t	(*t_breaker)(t_byte *, size_t);

static int	fd_cmp(void *key1, void *key2)
{
	return (key1 == key2 || *(int *)key1 == *(int *)key2);
}

// return -1 on break not found
// else returns the index of the break found
static ssize_t	find_eol(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(s + i) == '\0' || *(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_io_gnl(int fd)
{
	static t_kv	*store;
	t_iol		*result;
	char		*result_str;
	t_iol_el	*old_rest;
	t_iol_el	*new_rest;

	result = NULL;
	result_str = NULL;
	if (store == NULL)
		store = ft_kv_init(fd_cmp);
	old_rest = ft_kv_get(store, &fd);
	if (old_rest)
		ft_iol_append(result, );
	new_rest = ft_iol_read_till(result, fd, find_eol);
	return (result_str);
}
