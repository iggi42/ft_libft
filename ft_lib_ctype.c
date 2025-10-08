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
#include "./libft.h"

// TODO test if EOF return false for all these functions

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

int		ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int		ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int		ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
