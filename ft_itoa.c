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

#include <stdio.h>

static char *base_str(long nb)
{
	size_t	size;

	size = 2;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb / 10 > 0)
	{
		nb /= 10;
		size++;
	}
	return (ft_calloc(size, sizeof(char)));
}

static size_t write2str(long nb, char* dst)
{
	size_t	size;

	if (nb == 0)
		return (0);
	size = write2str(nb / 10, dst);
	dst[size] = (nb % 10) + '0';
	return (size + 1);
}

char	*ft_itoa(int nb)
{
	char	*result;

	if(nb == 0)
		return (ft_strdup("0"));

	result = base_str(nb);
	if (result == NULL)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		write2str(((long) nb) * -1, result + 1);
	}
	else
		write2str(nb, result);
	return (result);
}
