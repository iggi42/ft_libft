/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:28:48 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/17 08:30:50 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *src, char const *set)
{
	char		*result;
	size_t		src_i;
	size_t		res_i;

	src_i = 0;
	res_i = 0;
	result = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	while (result != NULL && *(src + src_i) != '\0')
	{
		if (ft_strchr(set, *(src + src_i)) == NULL)
		{
			*(result + res_i) = *(src + src_i);
			res_i++;
		}
		src_i++;
	}
	return (result);
}
