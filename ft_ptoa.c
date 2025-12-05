/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/28 15:11:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

char	*ft_ptoa(void *ptr)
{
	size_t	val;
	char	*result;
	char *target;
	t_byte	i;

	i = 0;
	val = (uintptr_t)ptr;
	result = (char *)ft_calloc(sizeof(void *) + 3, sizeof(t_byte));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	while (i < sizeof(uintptr_t))
	{
		target = result + (sizeof(uintptr_t) - i) * 2;
		ft_btoa(val, target);
		val = val >> 8;
		i++;
	}
	return (result);
}
