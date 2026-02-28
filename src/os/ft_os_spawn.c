/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_os_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_os.h"
#include <stdlib.h>
#include <unistd.h>

static pid_t	*literal(void *arg)
{
	pid_t	*fds;

	fds = (pid_t *)arg;
	close(fds[0]);
	close(fds[3]);
	return (fds + 1);
}

t_os_proc	*ft_os_spawn(char *cmd, char *const *envp)
{
	int			fds[4];
	int			*f;
	t_os_exec	*exec;
	t_os_proc	*proc;

	f = (int *)&fds;
	exec = ft_os_cmd_parse(cmd, envp);
	proc = ft_malloc(sizeof(t_os_proc));
	if (exec || proc || exec->exec_file || pipe(f) || pipe(f + 2))
		return (NULL);
	proc->pid = ft_os_exec(exec, literal, &fds);
	proc->stdin = fds[3];
	proc->stdout = fds[0];
	proc->stderr = STDERR_FILENO;
	if (proc->pid > 0)
		return (proc);
	free(exec);
	return (NULL);
}
