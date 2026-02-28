/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_cmd_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_mem.h"
#include "libft_os.h"
#include "libft_str.h"
#include <unistd.h>

static char	*get_env(char *envp[], char *s)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	while (*(envp + i))
	{
		if (ft_strncmp(*(envp + i), s, slen) == 0 && *(*(envp + i)
				+ slen) == '=')
			return (*(envp + i) + slen + 1);
		i++;
	}
	return (NULL);
}

static char	*find_in_path(char *cmd0, char *envp[])
{
	char	**paths;
	size_t	i;
	char	*full_path;

	if (ft_strncmp("./", cmd0, 2) == 0)
		return (ft_strdup(cmd0));
	paths = ft_split(get_env(envp, "PATH"), ':');
	i = 0;
	while (*(paths + i))
	{
		full_path = ft_strf("%s/%s", *(paths + i), cmd0);
		if (access(full_path, X_OK) == 0)
			return (free(paths), full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

t_os_exec	*ft_os_cmd_parse(char *cmd, char *const *envp)
{
	t_os_exec	*result;

	result = ft_malloc(sizeof(t_os_exec));
	if (result == NULL)
		return (NULL);
	result->argv = ft_split(cmd, ' ');
	result->envp = envp;
	result->exec_file = find_in_path(result->argv[0], (char **)envp);
	return (result);
}
