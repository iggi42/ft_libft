/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:12:32 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/17 08:35:13 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, const t_byte c, size_t n)
{
	if (n == 0)
		return (NULL);
	if (*(t_byte *) s == c)
		return ((void *) s);
	return (ft_memchr(s + 1, c, n - 1));
}
