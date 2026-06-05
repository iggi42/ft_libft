/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_cache.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:52:33 by fkruger           #+#    #+#             */
/*   Updated: 2026/04/23 17:52:34 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft_kv.h>
#include <libft_mem.h>
#include <stdbool.h>
#include <stddef.h>

static int	cmp_fd(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

static t_kv	*data(void)
{
	static t_kv	*core;

	if (core == NULL)
		core = ft_kv_init(cmp_fd);
	return (core);
}

void	*fdc_add(int fd, void *buffer)
{
	int	*new_key;

	new_key = (int *)ft_malloc(sizeof(int));
	*new_key = fd;
	ft_kv_put(data(), new_key, buffer);
	return (buffer);
}

// returns a char string with max size BUFFER_SIZE assigned to fd in earlier calls
// if fd is not yet associated with an buffer, new is called to create it
void *fdc_at(int fd, void *(new)(size_t size), size_t new_size)
{
	void	*result;

	if (fd < 0)
		return (NULL);
	result = ft_kv_get(data(), &fd);
	if (result != NULL)
		return (result);
	return (fdc_add(fd, new(new_size)));
}

void	*fdc_pop(int fd, void *(fallback)(size_t size), size_t new_size)
{
	t_kv_pair	*entry;
	char		*result;

	entry = ft_kv_pop(data(), &fd);
	if (entry == NULL)
		return (fallback(new_size));
	result = entry->val;
	ft_free(entry->key);
	ft_free(entry);
	return (result);
}

void	fdc_free(int fd)
{
	t_kv_pair	*entry;

	entry = ft_kv_pop(data(), &fd);
	if (entry == NULL)
		return ;
	ft_free(((t_kv_pair *)entry)->key);
	ft_free(((t_kv_pair *)entry)->val);
	ft_free(entry);
}
