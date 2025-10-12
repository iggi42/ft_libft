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
#include "./libft.h"
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	t_byte	*ptr;

	i = 0;
	ptr = (t_byte *) s;
	while (i < n)
	{
		ptr[i] = (t_byte) c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(((t_byte *) dest) + i) = *(((t_byte *) src) + i);
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t n_el, size_t el_size)
{
	void	*result;

	if (n_el == 0 || el_size == 0 || (SIZE_MAX / n_el) < el_size)
		return (NULL);
	el_size *= n_el;
	result = malloc(el_size);
	ft_bzero(result, el_size);
	return (result);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_byte buffer;
	
   if (n == 0)
		return 0;

	buffer = *(t_byte *) s1;
	if (buffer == 0)
		return (ft_memcmp(s1 + 1 , s2 + 2, n - 1));
	return (buffer);
}
