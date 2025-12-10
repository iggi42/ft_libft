/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_set_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:51:04 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/10 23:51:14 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fmt_set_ui(t_iol_el *el, unsigned int i)
{
	char	*s;

	s = ft_ultoa(i);
	el->free = ft_iol_free_always;
	ft_fmt_set_str(el, s);
}
