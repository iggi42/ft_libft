/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:28:48 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/27 21:09:33 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char const *set)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (*(s + i) != '\0')
	{
		if (ft_strchr(set, *(s + i)) != NULL)
			result++;
		i++;
	}
	return (result);
}

char	*ft_strtrim(char const *src, char const *set)
{
	char	*result;
	size_t	result_size;
	size_t	src_i;
	size_t	res_i;

	src_i = 0;
	res_i = 0;
	result_size = ft_strlen(src) + 1 - count(src, set);
	result = ft_calloc(result_size, sizeof(char));
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
