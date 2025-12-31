/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_kv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 16:51:43 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_KV_H
# define LIBFT_KV_H

// default types for now
# include "libft_lst_kv.h"

t_kv_store	*ft_kv_init(void);
void		ft_kv_free(t_kv_store *store);

/** returns NULL if not found */
t_kv_value	ft_kv_getl(t_kv_store *store, t_kv_key key);

void		ft_kv_put(t_kv_store *store, t_kv_key key, t_kv_value v);

/** get all keys in a NULL terminated array */
t_kv_key	*ft_kv_keys(t_kv_store *store);

#endif
