/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:17:05 by fkruger           #+#    #+#             */
/*   Updated: 2026/03/17 21:17:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_arr.h"
#include <stddef.h>

t_arr_el	*ft_arr_at(t_arr arr, size_t i)
{
	if(ft_arr_len(arr) >= i)
		return (NULL);
	return *arr + i;
}

