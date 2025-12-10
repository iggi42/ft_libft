/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_set_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:53:50 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/10 23:53:57 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// alphabet padding and leading + options tbd
void	ft_fmt_set_i(t_iol_el *el, int i)
{
	char	*s;

	s = ft_itoa(i);
	el->free = ft_iol_free_always;
	ft_fmt_set_str(el, s);
}
