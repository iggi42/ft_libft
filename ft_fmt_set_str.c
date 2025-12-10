/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_set_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:52:26 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/10 23:51:31 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fmt_set_str(t_iol_el *el, char *s)
{
	el->buffer = s;
	if (s == NULL)
		el->size = 0;
	else
		el->size = ft_strlen(s);
}
