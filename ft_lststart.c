/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/11/27 16:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_ll.h"
#include <stdlib.h>

t_list	**ft_lststart(t_list *head)
{
	t_list	**result;

	result = (t_list **)malloc(sizeof(t_list *));
	*result = head;
	return (result);
}
