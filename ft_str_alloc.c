/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iol_alloc.c                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/28 15:11:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_alloc(size_t len)
{
	char	*result;

	result = (char *)malloc((len + 1) * sizeof(char));
	ft_memset(result, '#', len);
	if (result)
		*(result + len) = '\0';
	return (result);
}
