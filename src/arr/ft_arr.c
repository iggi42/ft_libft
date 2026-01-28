/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/28 15:11:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_arr.h"
#include "libft_mem.h"

void	**ft_arr_new(size_t size)
{
	return (ft_calloc(size + 1, sizeof(void *)));
}

size_t	ft_arr_len(void *ar)
{
	size_t	i;
	void	**arr;

	arr = ar;
	i = 0;
	while (*(arr + i))
		i++;
	return (i);
}
