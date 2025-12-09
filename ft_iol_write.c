/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iol_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/02 19:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

// TODO change return type to a much larger number
int	ft_iol_write(t_list *l, int fd)
{
	t_iol_el	*el;
	int			result;
	int			write_code;

	result = 0;
	while (l != NULL)
	{
		el = (t_iol_el *)l->content;
		write_code = write(fd, el->buffer, el->size);
		if (write_code < 0)
			return (write_code);
		result += write_code;
		l = l->next;
	}
	return (result);
}
