/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:17:42 by fkruger           #+#    #+#             */
/*   Updated: 2025/09/30 20:24:17 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdbool.h>
#include "./ft_lib.h"

void	*memset(void *s, int c, size_t n)
{
	size_t	i;
	int		*ptr;

	i = 0;
	ptr = (int *) s;
	while (i <= n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (s);
}

void	bzero(void *s, size_t n)
{
	memset(s, 0, n);
}


//TODO 
void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}

void	*memmove(void *dest, const void *src, size_t n)
{
}
