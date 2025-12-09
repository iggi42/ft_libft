/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/01 19:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_buf	*ft_buf_new(size_t size)
{
	t_buf	*result;

	result = (t_buf *)malloc(sizeof(t_buf));
	if (result == NULL)
		return (NULL);
	result->size = size;
	result->p = (t_byte *)malloc(size * sizeof(t_byte));
	if (result->p)
		return (result);
	free(result);
	return (NULL);
}
