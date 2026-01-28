/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:14:29 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/09 16:46:33 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_ll.h"

void	ft_lstadd_front(t_list **lst, t_list *new_l)
{
	new_l->next = *lst;
	*lst = new_l;
}
