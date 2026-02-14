/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spawn_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_os.h"
#include "libft_str.h"
#include "libft_io.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

static void	mk_std(int *pipes)
{
	if (pipes == NULL)
		return ;
	dup2(pipes[0], STDIN_FILENO);
	dup2(pipes[1], STDOUT_FILENO);
}

// This doesn't handle envs in the beginning of the line yet
// nor dies it escape space via \ ' or "
// sets fds from io like this:
// STDIN_FILENO  <= io[0]
// STDOUT_FILENO <= io[1]
// or just leave the std fds alone if NULL is passed as io parameter
pid_t	ft_spawn_cmd(char *cmd, char *const *envp, int *io, void (*cleanup_fds)(void))
{
	char	**cmd_ar;
	char	*exec_file;
	pid_t	child_pid;

	cmd_ar = ft_split(cmd, ' ');
	exec_file = find_in_path(cmd_ar[0], (char **)envp);
	if (exec_file == NULL)
	{
		// TODO fix this stupid hack, use perror
		ft_printf_fd(STDERR_FILENO, "libft:ft_spawn_cmd: %s not found\n", cmd_ar[0]);
		return (free(cmd_ar), free(exec_file), -1);
	}
	child_pid = fork();
	if (child_pid == -1)
		(perror("fork"), exit(EXIT_FAILURE));
	if (child_pid != 0)
		return (free(cmd_ar), free(exec_file), child_pid);
	mk_std(io);
	cleanup_fds();
	ft_execve(exec_file, cmd_ar, envp);
	return -1;
}
