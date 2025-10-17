/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:15:23 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/17 11:22:40 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == '\0')
	{
		if (c == '\0')
			return ((char *) s);
		else
			return (NULL);
	}
	if (*s == c)
		return ((char *) s);
	else
		return (ft_strchr(s + 1, c));
}
