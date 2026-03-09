/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_arr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:04 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARR_H
# define LIBFT_ARR_H
# include "libft_arr_t.h"
# include <stddef.h>

t_arr	*ft_arr_new(size_t size);
size_t	ft_arr_len(t_arr arr);

// call 'apply' against each element of the array
void	ft_arr_each(t_arr arr, t_arr_scal apply);

// call 'apply' against the first n elements of the array
//   (ignores NULL terminators and feed them into apply instead).
void	ft_arr_neach(t_arr arr, size_t n, t_arr_scal apply);

t_arr	*ft_arr_map(t_arr arr, t_arr_scal apply);

// fold (from lower to higher index) over the given array
// void* fold(void *acc, void *arr_el)
void	*ft_arr_fold(t_arr arr, void *(*fold)(void *, void *), void *acc);

#endif
