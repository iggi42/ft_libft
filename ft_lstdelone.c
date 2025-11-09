/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:33:11 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/09 16:50:39 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*nxt;

	del(lst->content);
	nxt = lst->next;
	if (nxt != NULL)
	{
		lst->next = nxt->next;
		lst->content = nxt->content;
	}
	free(nxt);
}
