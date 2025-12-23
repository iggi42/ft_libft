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
# include <stdarg.h>
# include "libft_iol.h"

//! @brief format a string template into a io list for
t_list	*ft_fmt_parse(const char *tmpl);

//! @brief apply printf style operators to the parsed template
void	ft_fmt_apply(t_list *io_list, va_list args);

#endif
