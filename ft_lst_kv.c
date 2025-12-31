/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_kv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/27 16:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_kv.h"
#include "libft_ll.h"
#include "libft_lst_kv.h"
#include <stdlib.h>

t_kv_store	*ft_kv_init(void)
{
	return (NULL);
}

void	ft_kv_free(t_kv_store *store)
{
	ft_lstclear(store, free);
}

/** returns NULL if not found */
t_kv_value	ft_kv_getl(t_kv_store *store, t_kv_key key);

void		ft_kv_put(t_kv_store *store, t_kv_key key, t_kv_value v);

/** get all keys in a NULL terminated array */
t_kv_key	*ft_kv_keys(t_kv_store *store);
