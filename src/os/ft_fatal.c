/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:35:38 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/28 15:11:25 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#ifdef FTLIB_F_PERROR
# include <stdio.h>

void	ft_fatal(void)
{
	perror("FATAL: ");
	exit(EXIT_FAILURE);
}

#else

void	ft_fatal(void)
{
	exit(EXIT_FAILURE);
}

#endif
