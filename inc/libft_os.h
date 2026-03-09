/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_os.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:04 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_OS_H
# define LIBFT_OS_H

# include <unistd.h>

//! describes an operating system process
typedef struct s_os_proc
{
	int		stdin;
	int		stdout;
	int		stderr;
	int		pid;
}			t_os_proc;

//! this struct contains everything you need to start an new OS process in a normal way
typedef struct s_os_exec
{
	char	*exec_file;
	char *const *argv;
	char *const *envp;
}			t_os_exec;

//! parse a cmd call
t_os_exec	*ft_os_cmd_parse(char *cmd, char *const *envp);

//! execute a parsed cmd call
pid_t		ft_os_exec(t_os_exec *exec, int *(*setup)(void *arg),
				void *setup_arg);

//! parse a cmd call
t_os_proc	*ft_os_spawn(char *cmd, char *const *envp);

//! cleans up a spawn process (no zombies, closed fds, etc), returns exit code
int			ft_os_proc_cleanup(t_os_proc *proc);

//! end the current process (depends on what functions are allowed to call)
void		ft_fatal(void);

//! experimental wrap around execve
void		ft_execve(const char *exec_file, char *const *argv,
				char *const *envp);

#endif
