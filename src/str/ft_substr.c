/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:31:03 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:07 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_mem.h"
#include "libft_str.h"
#include <stddef.h>

char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	input_len;
	char	*result;

	if (s == NULL)
		return (NULL);
	input_len = ft_strlen(s);
	if (start > input_len)
		return (ft_strdup(""));
	if (start + len > input_len)
		return (ft_strdup(s + start));
	result = ft_str_alloc(len);
	ft_memcpy(result, s + start, len);
	return (result);
}
