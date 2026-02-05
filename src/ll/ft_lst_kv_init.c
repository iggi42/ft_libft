/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_kv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 07:18:32 by fkruger           #+#    #+#             */
/*   Updated: 2026/01/27 13:19:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_kv.h"
#include "libft_ll.h"
#include "libft_lst_kv.h"
#include "libft_mem.h"

t_kv	*ft_kv_init(t_kv_key_cmp key_cmp)
{
	t_kv	*result;

	result = ft_malloc(sizeof(t_kv));
	result->_store = NULL;
	result->key_cmp = key_cmp;
	return (result);
}
