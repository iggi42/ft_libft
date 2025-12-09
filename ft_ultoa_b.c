/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/01 19:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_b(unsigned long nb, const char *alphabet)
{
	size_t	size;
	char	*result;

	size = ft_ultoa_bl(nb, NULL, 0, alphabet);
	result = ft_str_alloc(size);
	ft_ultoa_bl(nb, result, size, alphabet);
	return (result);
}
