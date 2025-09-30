/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:30:47 by fkruger           #+#    #+#             */
/*   Updated: 2025/09/30 19:45:33 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdbool.h>
#include "./ft_lib.h"

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int		ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

int		ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
