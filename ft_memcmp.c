/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:17:42 by fkruger           #+#    #+#             */
/*   Updated: 2025/09/30 20:24:17 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t n)
{
	int buffer;
	t_byte *b1;
	t_byte *b2;
	
   if (n == 0)
		return 0;

	b1 = (t_byte *) m1;
	b2 = (t_byte *) m2;
	buffer = *b1 - *b2;
	if (buffer == 0)
		return (ft_memcmp(b1 + 1 , b2 + 1, n - 1));
	return (buffer);
}
