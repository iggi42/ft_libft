/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fmt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 16:51:43 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FMT_H
# define LIBFT_FMT_H

//! @name string format
//!@{

char	*ft_fmt_str(const char *tmpl, ...);

// TODO: document what operators are implemented
/**
 * @brief you know what a printf does, come on
 */
int		ft_printf(const char *tmpl, ...);
//!@}

#endif
