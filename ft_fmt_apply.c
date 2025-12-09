/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:19:02 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/01 19:29:16 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	replace_op_str(t_iol_el *el, char *s)
{
	el->buffer = s;
	if (s == NULL)
		el->size = 0;
	else
		el->size = ft_strlen(s);
}

static void	replace_op_c(t_iol_el *el, char c)
{
	el->buffer = malloc(sizeof(char));
	if (el->buffer)
	{
		*(el->buffer) = c;
		el->size = sizeof(char);
		el->free = ft_iol_free_always;
	}
}

static void	replace_op_pointer(t_iol_el *el, void *ptr)
{
	char	*s;

	if (ptr == NULL)
		s = "(nil)";
	else
	{
		s = ft_ptoa_b(ptr, FT_ALPHABET_HEX_LOW);
		el->free = ft_iol_free_always;
	}
	replace_op_str(el, s);
}

static void	replace_op_i(t_iol_el *el, int i)
{
	char	*s;

	s = ft_itoa(i);
	el->free = ft_iol_free_always;
	replace_op_str(el, s);
}

static void	replace_op_u(t_iol_el *el, unsigned int i)
{
	char	*s;

	s = ft_ultoa(i);
	el->free = ft_iol_free_always;
	replace_op_str(el, s);
}

static void	replace_op_x(t_iol_el *el, unsigned int x)
{
	char	*s;

	s = ft_ultoa_b(x, FT_ALPHABET_HEX_LOW);
	el->free = ft_iol_free_always;
	replace_op_str(el, s);
}

static void	replace_op_xx(t_iol_el *el, unsigned int x)
{
	char	*s;

	s = ft_ultoa_b(x, FT_ALPHABET_HEX);
	el->free = ft_iol_free_always;
	replace_op_str(el, s);
}

static void	replace_op(t_iol_el *el, va_list args)
{
	char	type;

	if (el->size < 2 || *(el->buffer) != '%')
		return ;
	type = *(el->buffer + 1);
	if (type == '%')
		el->size = sizeof(char);
	else if (type == 's')
		replace_op_str(el, va_arg(args, char *));
	else if (type == 'c')
		replace_op_c(el, (char)va_arg(args, int));
	else if (type == 'p')
		replace_op_pointer(el, (void *)va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		replace_op_i(el, (int)va_arg(args, int));
	else if (type == 'u')
		replace_op_u(el, (unsigned int)va_arg(args, unsigned int));
	else if (type == 'x')
		replace_op_x(el, (unsigned int)va_arg(args, unsigned int));
	else if (type == 'X')
		replace_op_xx(el, (unsigned int)va_arg(args, unsigned int));
}

void	ft_fmt_apply(t_list *io_list, va_list args)
{
	if (io_list == NULL)
		return ;
	replace_op(io_list->content, args);
	ft_fmt_apply(io_list->next, args);
}
