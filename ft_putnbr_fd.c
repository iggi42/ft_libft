/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:38:05 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/27 21:39:40 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

static void	ft_print_number(int nb, int fd)
{
	char	digit;

	if (nb == 0)
		return ;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	digit = (nb % 10) + '0';
	ft_print_number(nb / 10, fd);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		write(fd, "0", 1);
	else if (nb == INT_MIN)
		write(fd, "-2147483648", 11);
	else
		ft_print_number(nb, fd);
}
