/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:18:21 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/17 08:18:24 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_l;

	dst_l = ft_strlen(dst);
	return (ft_strlcpy(dst + dst_l, src, dst_size - dst_l) + dst_l);
}
