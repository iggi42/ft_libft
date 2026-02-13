/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:04 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_arr.h"
#include "libft_mem.h"

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
