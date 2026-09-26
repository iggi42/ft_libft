/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 05:37:35 by fkruger           #+#    #+#             */
/*   Updated: 2026/04/07 05:37:35 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_merle.h"
#include "m3_priv.h"
#include <stdbool.h>
#include <stdlib.h>

static t_m3_ref	**ft_m3_root(void)
{
	static t_m3_ref	*core_head;

	return (&core_head);
}

bool	ft_m3_add(void *ptr)
{
	t_m3_ref	*new_head;

	if (ptr == NULL)
		return (false);
	new_head = malloc(sizeof(t_m3_ref));
	if (new_head == NULL)
		return (false);
	new_head->next = *ft_m3_root();
	new_head->ptr = ptr;
	*ft_m3_root() = new_head;
	return (true);
}

bool	ft_m3_rm(void *ptr)
{
	t_m3_ref	**curr;
	t_m3_ref	*cache;
	bool		result;

	if (ptr == NULL)
		return (false);
	curr = ft_m3_root();
	result = false;
	while (*curr)
	{
		if ((*curr)->ptr == ptr)
		{
			cache = *curr;
			*curr = (*curr)->next;
			result = true;
			free(cache);
		}
		else
			curr = &(*curr)->next;
	}
	return (result);
}

void	ft_m3_each(void (*apply)(void *ptr))
{
	t_m3_ref	*curr;

	curr = *ft_m3_root();
	while (curr)
	{
		apply(curr->ptr);
		curr = curr->next;
	}
}

void	ft_m3_cleanup(void)
{
	t_m3_ref	*curr;
	t_m3_ref	*cache;

	curr = *ft_m3_root();
	while (curr)
	{
		free(curr->ptr);
		cache = curr;
		curr = curr->next;
		free(cache);
	}
	*ft_m3_root() = NULL;
}
