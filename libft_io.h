/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 16:51:43 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//! @name IO
//!@{
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//!@}

#define ft_printf(...) ft_printf_fd(1, __VA_ARGS__)

//! @brief you know what a printf does, come on
int		ft_printf_fd(int fd, const char *tmpl, ...);

//! a simple get next line (ft_buf -based for now)
char	*ft_gnl(int fd);

#endif
