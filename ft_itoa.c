/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/27 23:24:41 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

static size_t i2a(long n, char* dst)
{
	size_t	size;

	if (n == 0)
		return 0;
	size = i2a(nb / 10, dst);
	dst[size] = (nb % 10) + '0';
	return (size + 1);
}

char	*ft_itoa(int nb)
{
	char	*result;
	size_t	size;

	if (nb < 0)
	{
		*dst = '-';
		nb *= -1;
		dst++;
	}
	digit = (nb % 10) + '0';
	size = n2a(nb / 10, dst);
	*dst = digit;
}
