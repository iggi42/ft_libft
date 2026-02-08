/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_os.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/11 01:02:46 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_OS_H
# define LIBFT_OS_H

typedef struct s_os_proc
{
	int		stdin;
	int		stdout;
	int		stderr;
	int		pid;
}			t_os_proc;

void		ft_fatal(void);
void		ft_execve(const char *exec_file, char *const *argv,
				char *const *envp);

int			ft_spawn_cmd(char *cmd, char *const *envp, int *redirects, void (*cleanup)(void));

t_os_proc	*ft_os_spawn(char *cmd, char *const *envp, void (*cleanup)(void));

void		ft_os_proc_cleanup(t_os_proc *proc);

#endif
