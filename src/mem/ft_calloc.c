/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:50 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/27 16:22:35 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_mem.h"
#include <stdint.h>

void	*ft_calloc(size_t n_el, size_t el_size)
{
	void	*result;

	if (n_el == 0 || el_size == 0 || (SIZE_MAX / n_el) < el_size)
		result = NULL;
	else
	{
		el_size *= n_el;
		result = malloc(el_size);
		if (result != NULL)
			ft_bzero(result, el_size);
	}
	return (result);
}
