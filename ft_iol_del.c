/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iol_del.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/28 15:11:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_iol.h"

static void	cleanup_iol_el(void *ptr)
{
	t_iol_el	*el;

	el = ptr;
	if (el != NULL && el->free != NULL)
		el->free(el);
	free(el);
}

void	ft_iol_del(t_list **l)
{
	ft_lstclear(l, cleanup_iol_el);
}
