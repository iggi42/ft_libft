/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:30:47 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/25 14:03:33 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	*runner;

	found = NULL;
	runner = (char *)s;
	while (*runner != '\0')
	{
		if (*runner == ((char)c))
			found = runner;
		runner++;
	}
	if (c == '\0')
		return (runner);
	else
		return (found);
}
