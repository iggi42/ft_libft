/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:31:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/26 13:55:09 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	long	output_len;

	i = 0;
	output_len = ft_strlen(s) - start;
	if (output_len <= 0)
		return (ft_calloc(1, sizeof(char)));
	result = ft_calloc(output_len + 1, sizeof(char));
	while (*(s + start + i) && i < len)
	{
		*(result + i) = *(s + start + i);
		i++;
	}
	return (result);
}
