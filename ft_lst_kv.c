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

#include "libft_arr.h"
#include "libft_kv.h"
#include "libft_ll.h"
#include "libft_lst_kv.h"
#include "libft_mem.h"
#include <stdlib.h>

t_kv_store	*ft_kv_init(void)
{
	return (ft_calloc(1, sizeof(void *)));
}

void	ft_kv_free(t_kv_store *store)
{
	ft_lstclear(store, free);
}

//! returns NULL if not found
t_kv_value	ft_kv_get(t_kv_store *store, t_kv_key key)
{
	t_list		*head;
	t_kv_pair	*kv;

	head = *store;
	while (head != NULL)
	{
		kv = head->content;
		if (kv->key == key)
			return (kv->val);
		head = head->next;
	}
	return (NULL);
}

void	ft_kv_put(t_kv_store *store, t_kv_key key, t_kv_value v)
{
	t_kv_pair	*kv;

	while (*store != NULL)
	{
		kv = (*store)->content;
		if (kv->key == key)
		{
			kv->val = v;
			return ;
		}
		store = &((*store)->next);
	}
	kv = ft_malloc(sizeof(t_kv_pair));
	kv->key = key;
	kv->val = v;
	*store = ft_lstnew(kv);
}

//! get all keys in a freeable, NULL terminated array
t_kv_key	*ft_kv_keys(t_kv_store *store)
{
	size_t		s;
	size_t		i;
	t_kv_key	*result;
	t_list		*head;

	i = 0;
	head = *store;
	s = ft_lstsize(*store);
	result = ft_arr_new(s);
	while (i < s)
	{
		*(result + i++) = ((t_kv_pair *)head->content)->key;
		head = head->next;
	}
	return (result);
}
