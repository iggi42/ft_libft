/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/27 16:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdarg.h>

void	*ft_free(void *first, ...)
{
	va_list	args;
	void	**target;

	target = first;
	va_start(args, first);
	while (target)
	{
		free(*target);
		*target = NULL;
		target = (void **)va_arg(args, void **);
	}
	va_end(args);
	return (NULL);
}
