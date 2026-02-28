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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	mk_std(int *(*setup_io)(void *arg), void *setup_io_arg)
{
	int	*pipes;

	if (setup_io == NULL)
		return ;
	pipes = setup_io(setup_io_arg);
	if (pipes == NULL)
		return ;
	dup2(pipes[0], STDIN_FILENO);
	dup2(pipes[1], STDOUT_FILENO);
}

// assumes a correctly set exec
pid_t	ft_os_exec(t_os_exec *exec, int *(*setup_io)(void *arg),
		void *setup_io_arg)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
		(perror("fork"), exit(EXIT_FAILURE));
	if (child_pid > 0)
		return (child_pid);
	mk_std(setup_io, setup_io_arg);
	ft_execve(exec->exec_file, exec->argv, exec->envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
