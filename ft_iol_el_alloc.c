/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iol_el_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/27 16:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_iol_el	*ft_iol_el_alloc(size_t size)
{
	t_iol_el	*seg;
	char		*start;

	seg = (t_iol_el *)malloc(sizeof(t_iol_el));
	start = (char *)malloc(size);
	if (seg == NULL || start == NULL)
	{
		ft_free(&seg, &start);
		return (NULL);
	}
	seg->buffer = start;
	seg->size = size;
	seg->free = ft_iol_free_always;
	return (seg);
}
