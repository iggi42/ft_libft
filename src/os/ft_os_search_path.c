/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_search_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_arr.h"
#include "libft_os.h"
#include "libft_str.h"
#include <unistd.h>

static char	*get_env(char *const *envp, char *key, char *fall_back)
{
	size_t	i;
	size_t	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
			return (envp[i] + key_len + 1);
		i++;
	}
	return (fall_back);
}

char	*ft_os_search_path(char *cmd0, char *const *envp)
{
	char	**paths;
	size_t	i;
	char	*full_path;

	if (!*cmd0)
		return (NULL);
	paths = ft_split(get_env(envp, "PATH", "."), ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strf("%s/%s", paths[i], cmd0);
		if (access(full_path, X_OK) == 0)
			return (ft_arr_each((t_arr)paths, free), free(paths), full_path);
		free(full_path);
		i++;
	}
	if (paths)
		ft_arr_each((t_arr)paths, free);
	return (free(paths), NULL);
}
