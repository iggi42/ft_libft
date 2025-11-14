/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:43:06 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/09 16:47:37 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstcut(t_list *lst, void (*del)(void *))
{
	t_list	*nxt;

	if (lst == NULL)
		return ;
	del(lst->content);
	nxt = lst->next;
	free(lst);
	ft_lstcut(nxt, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	start = *lst;
	*lst = NULL;
	ft_lstcut(start, del);
}
