/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:18:21 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/26 09:42:42 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_l;

	dst_l = ft_strlen(dst);
	if (dst_l >= dst_size)
		dst_l = dst_size;
	return (dst_l + ft_strlcpy(dst + dst_l, src, dst_size - dst_l));
}
